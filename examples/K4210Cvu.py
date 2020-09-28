# Copyright (C) 2020 Torsten Brischalle
# 
# AutomatisierungsTechnik Voigt GmbH
# Heilbronner Str. 17
# 01189 Dresden
# Germany
# 
# web:   https://www.atv-systems.de
# email: atv@atv-systems.de
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
#
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
# LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
# WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

# import LPT library functions
import k4200lptlibrary as lpt

# import LPT library instrument IDs
import k4200instruments as inst

# import LPT library parameter constants
import k4200parameters as param

# import message box
from MessageBox import *

# enums for constants
from enum import IntEnum
from enum import Enum

import os
import errno

class K4210CvuSpeed(IntEnum):
    """
    CVU speed constants.
    """
    Fast = 0
    Normal = 1
    Slow = 2

class K4210CvuRange(Enum):
    """
    CVU range constants.
    """
    Auto = 0
    Range1uA = 1E-6
    Range30uA = 30E-6
    Range1mA = 1E-3

class K4210Cvu:
    """
    Class to control the Keithley 4210 CVU.
    This class uses the LPT library. The LPT library has to be initialized before this class is used first time.
    """

    # Number (#) used to create the constants#.xml file.
    ConstantFileNameIndex = 0

    # Cable length used in setup (0, 1.5, 3) (in meters).
    CableLength = 1.5
    
    __cvuName = ""
    __cvuId = 0
    
    #-----------------------------------------------------------------------------------------------
        
    def __init__(self, cvuName):
        """
        Creates a new CVU instance.
        
        :param cvuName: The CVU instrument name, e.g. CVU1.
        """
        self.__cvuName = cvuName
        self.__cvuId = lpt.getinstid(cvuName)
        
    #-----------------------------------------------------------------------------------------------
        
    def MakeCompensation(self, selectOpen = True, selectShort = True, selectLoad = True, loadValue = 50.0):
        """
        Make CVU open, short and load compensation.

        :param selectOpen: Run CVU open compensation.
        :param selectShort: Run CVU short compensation.
        :param selectLoad: Run CVU load compensation.
        :param loadValue: Load value used for load compensation on CVU.
        """
        
        lpt.setmode(self.__cvuId, param.KI_CVU_SET_CONSTANT_FILE, self.ConstantFileNameIndex)
        lpt.setmode(self.__cvuId, param.KI_CVU_CABLE_CORRECT, self.CableLength)

        if selectOpen:
            if ShowMessageBox("Action Required", "Perform CVU open compensation.\nDisconnect output connections from any DUT.", MessageBoxType.OkCancel) == MessageBoxReturn.Ok:
                # perform open compensation on CVU
                lpt.cvu_open_comp(self.__cvuId)

        if selectShort:
            if ShowMessageBox("Action Required", "Perform CVU short compensation.\nConnect Hi to Lo output connections together.", MessageBoxType.OkCancel) == MessageBoxReturn.Ok:
                # perform short compensation on CVU
                lpt.cvu_short_comp(self.__cvuId)

        if selectLoad:
            if ShowMessageBox("Action Required", "Perform CVU load compensation.\nApply load across Hi & Lo connections.", MessageBoxType.OkCancel) == MessageBoxReturn.Ok:
                # perform load compensation on CVU
                lpt.cvu_load_comp(self.__cvuId, loadValue)

    #-----------------------------------------------------------------------------------------------
        
    def LoadCompensationConstants(self):
        """
        Loads a compensation constants file.

        :param constantFileNameIndex: Number (#) used to create the constants#.xml file.
        """
        if self.ConstantFileNameIndex > 0:
            constantFileName = "c:\\s4200\\sys\\constants\\constants{}.xml".format(self.ConstantFileNameIndex)
        else:
            constantFileName = "c:\\s4200\\sys\\constants\\constants.xml"

        if not os.path.exists(constantFileName):
            raise FileNotFoundError(errno.ENOENT, os.strerror(errno.ENOENT), constantFileName)

        lpt.setmode(self.__cvuId, param.KI_CVU_SET_CONSTANT_FILE, self.ConstantFileNameIndex)

    #-----------------------------------------------------------------------------------------------
        
    def MeasureCV(self,
                  dcVoltageStart, dcVoltageEnd, dcVoltageStep,
                  settlingTime,
                  acVoltage, acFrequency,
                  initialDelay = 0.5,
                  cvuRange = K4210CvuRange.Auto,
                  cvuSpeed = K4210CvuSpeed.Normal,
                  openCompensation = False, shortCompensation = False, loadCompensation = 0):
        """
        Performs a CV measurement.

        :param dcVoltageStart:
        :param dcVoltageEnd:
        :param dcVoltageStep:
        :param settlingTime: Settling time in seconds for DC voltage sweep.
        :param acVoltage: AC voltage level (1e-3 to 0.1).
        :param acFrequency: Frequence for CVU AC voltage (10 kHz to 10 MHz).
        :param initialDelay: Delay time after apply first voltage and before the first measurement starts.
        :param cvuRange: CVU measurement range (see K4210CvuRange).
        :param cvuSpeed: CVU measurement speed (see K4210CvuSpeed).
        """

        cvuId = self.__cvuId

        dcVoltMax = max(abs(dcVoltageStart), abs(dcVoltageEnd))
        dcVoltPoints = int(round((dcVoltageEnd - dcVoltageStart) / dcVoltageStep + 1.0))

        # initialize CVU
        lpt.forcev(cvuId, 0)

        # configure compensation
        lpt.setmode(cvuId, param.KI_CVU_OPEN_COMPENSATE, 1 if openCompensation else 0)
        lpt.setmode(cvuId, param.KI_CVU_SHORT_COMPENSATE, 1 if shortCompensation else 0)
        lpt.setmode(cvuId, param.KI_CVU_LOAD_COMPENSATE, loadCompensation)

        # set AC voltage
        lpt.setlevel(cvuId, acVoltage)
        lpt.setfreq(cvuId, acFrequency)
        lpt.rangei(cvuId, cvuRange.value)

        # CVU speed settings
        cvuSpeedVal = param.KI_CVU_SPEED_NORMAL
        
        if cvuSpeed == K4210CvuSpeed.Fast:
            cvuSpeedVal = param.KI_CVU_SPEED_FAST
            
        if cvuSpeed == K4210CvuSpeed.Slow:
            cvuSpeedVal = param.KI_CVU_SPEED_QUIET
        
        vArr = []
        cpArr = []
        gpArr = []
        tArr = []

        # apply first voltage
        lpt.forcev(cvuId, dcVoltageStart)
        lpt.delay(int(initialDelay * 1000))
        
        # sweep DC voltage
        for dcVoltIndex in range(0, dcVoltPoints):

            dcVolt = dcVoltageStart + dcVoltageStep * dcVoltIndex

            # force DC voltage
            lpt.forcev(cvuId, dcVolt)
            lpt.delay(int(settlingTime * 1000))

            # measure impedance
            cp, gp = lpt.measz(cvuId, param.KI_CVU_TYPE_CPGP, cvuSpeedVal)
            t = lpt.meast(cvuId)

            stat = int(lpt.getstatus(cvuId, param.KI_CVU_MEASURE_STATUS))
            if (stat & (~3)) != 0:
                raise RuntimeError("CVU error: {}".format(stat))
            
            # store values
            vArr.append(dcVolt)
            cpArr.append(cp)
            gpArr.append(gp)
            tArr.append(t)
        
        # set all sources to zero
        lpt.devint()

        return vArr, cpArr, gpArr, tArr
    













    

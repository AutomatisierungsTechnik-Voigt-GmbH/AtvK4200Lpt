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

# import plot library
import matplotlib.pyplot as plt

# import TK for gui
import tkinter as tk
import tkinter.messagebox as msgbox

def Initialize():
    """
    Initializes the K4200.
    """

    # load lpt library
    lpt.initialize()

    # initialie K4200
    lpt.tstsel(1)
    lpt.devint()

def CvuCompensation(cableLength, selectOpen = True, selectShort = True, selectLoad = True, loadValue = 50.0, constantFileNameIndex = 1):
    """
    Make CVU open, short and load compensation.

    :param cableLength: Cable length used in setup (0, 1.5, 3) (in meters).
    :param selectOpen: Run CVU open compensation.
    :param selectShort: Run CVU short compensation.
    :param selectLoad: Run CVU load compensation.
    :param loadValue: Load value used for load compensation on CVU.
    :param constantFileNameIndex: Number (#) used to create the constants#.htm file.
    """
    
    # get CVU instrument ID
    cvu = lpt.getinstid("CVU1")

    lpt.setmode(cvu, param.KI_CVU_SET_CONSTANT_FILE, constantFileNameIndex);
    lpt.setmode(cvu, param.KI_CVU_CABLE_CORRECT, cableLength);

    if selectOpen:
        if msgbox.askokcancel("Action Required", "Perform CVU open compensation.\nDisconnect output connections from any DUT."):
            # perform open compensation on CVU
            lpt.cvu_open_comp(cvu);

    if selectShort:
        if msgbox.askokcancel("Action Required", "Perform CVU short compensation.\nConnect Hi to Lo output connections together."):
            # perform short compensation on CVU
            lpt.cvu_short_comp(cvu);

    if selectShort:
        if msgbox.askokcancel("Action Required", "Perform CVU load compensation.\nApply load across Hi & Lo connections."):
            # perform load compensation on CVU
            lpt.cvu_load_comp(cvu, loadValue);

# Main
Initialize()
CvuCompensation(1.5)















    

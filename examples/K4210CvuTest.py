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

from K4210Cvu import *

def Initialize():
    """
    Initializes the K4200.
    """

    # load lpt library
    lpt.initialize()

    # initialie K4200
    lpt.tstsel(1)
    lpt.devint()

# Main
Initialize()

cvu = K4210Cvu("CVU1")
cvu.CableLength = 1.5

#cvu.MakeCompensation(selectLoad = False)
#cvu.LoadCompensationConstants()

vArr, cpArr, gpArr, tArr = cvu.MeasureCV(dcVoltStart = -5.0,
                                         dcVoltEnd = 5.0,
                                         dcVoltStep = 0.1,
                                         tSet = 0.1,
                                         initialDelay = 1.0,
                                         acVoltage = 50E-3,
                                         frequency = 100E3,
                                         cvuSpeed = K4210CvuSpeed.Slow)


# initialize plot
plt.ion()
fig = plt.figure()
axes = fig.add_subplot(111)
line, = axes.plot(vArr, cpArr, 'b-')

plt.title("CV Sweep")
plt.xlabel("Voltage (V)") 
plt.ylabel("Cp (F)")
plt.grid(True)


# update plot curve
#line.set_data(vArr, cpArr)

axes.relim()
axes.autoscale_view(True, True, True)
fig.canvas.draw()












    

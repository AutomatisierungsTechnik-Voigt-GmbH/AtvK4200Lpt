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

# K4200 python lpt library example

# import LPT library functions
import k4200lptlibrary as lpt

# import LPT library instrument IDs
import k4200instruments as inst

# import LPT library parameter constants
import k4200parameters as param

# import plot library
import matplotlib.pyplot as plt

# Function to measure mosfet transfer curve.
def MosfetOutputCurve(gateStartVolt, gateEndVolt, gateStepVolt, drainStartVolt, drainEndVolt, drainStepVolt):

    # load lpt library
    lpt.initialize()

    # initialie K4200
    lpt.tstsel(1)
    lpt.devint()

    # get gate, drain and source SMU
    smuGate = lpt.getinstid("SMU1")
    smuDrain = lpt.getinstid("SMU2")
    smuSource = lpt.getinstid("SMU3")

    # set limits and ranges
    lpt.limiti(smuGate, 1e-3)
    lpt.limiti(smuSource, 11E-3)
    lpt.limiti(smuDrain, 10E-3)
    
    lpt.lorangei(smuDrain, 1E-9)
    
    # set initial voltages
    lpt.forcev(smuSource, 0)
    lpt.forcev(smuGate, 0)
    lpt.forcev(smuDrain, 0)
    
    # set measurement integration time
    lpt.setmode(smuGate, param.KI_INTGPLC, 0.01);
    lpt.setmode(smuDrain, param.KI_INTGPLC, 0.01);

    # disable range delay
    lpt.setmode(smuDrain, param.KI_RANGE_DELAY, 0)
    
    # initialize plot
    plt.ion()
    fig = plt.figure()
    axes = fig.add_subplot(111)

    plt.title("Mosfet transfer curve")
    plt.xlabel("Gate voltage (V)") 
    plt.ylabel("Drain current (A)")
    plt.grid(True)

    # calculate point count
    gateIndexEnd = int(round((gateEndVolt - gateStartVolt) / gateStepVolt))
    drainIndexEnd = int(round((drainEndVolt - drainStartVolt) / drainStepVolt))
    
    # gate voltage loop
    for gateIndex in range(0, gateIndexEnd):

        # calculate and force gate voltage
        gateVolt = gateStartVolt + gateStepVolt * gateIndex
        lpt.forcev(smuGate, gateVolt)
        
        # initialize the arrays to store the measurement data
        vArr = []
        iArr = []

        line, = axes.plot(vArr, iArr, 'b-')
        
        # drain voltage loop
        for drainIndex in range(0, drainIndexEnd):

            # calculate and force drain voltage
            drainVolt = drainStartVolt + drainStepVolt * drainIndex
            lpt.forcev(smuDrain, drainVolt)

            # settling time 10 ms
            lpt.delay(10)

            # measue gate voltage and drain current
            v = lpt.intgv(smuDrain)
            i = lpt.intgi(smuDrain)
            
            # store measurement values in arrays
            vArr.append(v)
            iArr.append(i)

            # output gate voltage and drain current
            print("Gate: {:2.3f} V, Drain: {:2.3f} V, {:2.3g} mA".format(gateVolt, v, i * 1000.0))

            # update plot curve
            line.set_data(vArr, iArr)

            # autoscale plot
            axes.relim()
            axes.autoscale_view(True, True, True)

            # redraw curve
            fig.canvas.draw()

        # set drain voltage to 0 V before a new loop starts
        lpt.forcev(smuDrain, 0)
        
    # reset SMUs to default values
    lpt.devint()

# start transfer curve measurement
MosfetOutputCurve(1.5, 3, 0.25, 0, 3, 0.05)

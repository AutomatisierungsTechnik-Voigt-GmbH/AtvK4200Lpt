.. image:: https://www.atv-systems.de/around4/templates/atv2013/files/media/Logo/logo-atvoigt.png

| AutomatisierungsTechnik Voigt GmbH
| Heilbronner Str. 17
| 01189 Dresden
| Germany

| web: `<https://www.atv-systems.de>`_
| email: atv@atv-systems.de

***************************
ATV K4200 LPT Python Module
***************************

Preface
#######
This is a Python extensions module to control the Keithley 4200A-SCS instruments from
the Python programming language (Python version 3.8).

Hardware requirements
*********************
This Python extension module supports only the Keithley 4200A-SCS Parameter Analyzer.

Software requirements
*********************
The Keithley LPT library (linear parametric test library) is used to control the
Keithley 4200A-SCS instruments. This is a 32 bit library. Therefore you need a 32 bit Python version.

Download a 32 bit Python version (3.8.xx) here:

`<https://www.python.org/downloads/windows/>`_

Installation
############

Binary installer
****************
The easiest way to install the Keithley 4200A-SCS python extension module is to use
the binary installer:

`AtvK4200Lpt-1.0.win32-py3.8.exe <https://github.com/ATV-GmbH/AtvK4200Lpt/releases/download/1.0/AtvK4200Lpt-1.0.win32-py3.8.exe>`_

Manual Installation
*******************
You can install the extension module manually by copying the files from the build folder to the
Python extension module folder:

`/build/lib.win32-3.8 <https://github.com/ATV-GmbH/AtvK4200Lpt/tree/master/build/lib.win32-3.8>`_

Hints
#####
The Keithley 4200A-SCS sets the Python path and python home variables. This can cause problems if you
want to start your own installed Python environment (e.g. Python IDLE).

Use the batch file "Start Python IDLE.bat" to start IDLE with default Python path and home.
(`Start Python IDLE 3.8.bat <https://github.com/ATV-GmbH/AtvK4200Lpt/blob/master/Start%20Python%20IDLE%203.8.bat>`_)

Examples
########
Examples to use the Python module can be found in the examples folder:

`/examples <https://github.com/ATV-GmbH/AtvK4200Lpt/tree/master/examples>`_

Python usage
############

Step 1: import python modules
*****************************
.. code-block:: python

    # import LPT library functions
    import k4200lptlibrary as lpt

    # import LPT library instrument IDs
    import k4200instruments as inst

    # import LPT library parameter constants
    import k4200parameters as param

Step 2: initialize library and instruments
******************************************
.. code-block:: python

    # load lpt library
    lpt.initialize()

    # initialize K4200
    lpt.tstsel(1)
    lpt.devint()

Step 3: control instrument
**************************
.. code-block:: python

    # get gate, drain and source SMU
    smuGate = lpt.getinstid("SMU1")
    smuDrain = lpt.getinstid("SMU2")
    smuSource = lpt.getinstid("SMU3")

    # set limits and ranges
    lpt.limiti(smuGate, 1e-3)
    lpt.limiti(smuSource, 11E-3)
    lpt.limiti(smuDrain, 10E-3)

Documentation
#############
See Keithley 4200A-SCS reference manual for available LPT library functions und usage.

Build the module from source
############################
Requirements:

* Microsoft visual C/C++ compiler
* Python 3.8 (32 bit)

Use the batch files to build the module from source:

* module_build.bat: compiles the module (output to folder *build*)
* module_dist.bat: compiles the modules and creates the binary and source code installer (output to folder *dist*)
* module_install.bat: compiles the module and installs the module to the local Python environment.

Athor
#####
Torsten Brischalle

| AutomatisierungsTechnik Voigt GmbH
| Heilbronner Str. 17
| 01189 Dresden
| Germany

| web:   https://www.atv-systems.de
| email: atv@atv-systems.de

/*
 * Copyright (C) 2020 Torsten Brischalle
 *
 * AutomatisierungsTechnik Voigt GmbH
 * Heilbronner Str. 17
 * 01189 Dresden
 * Germany
 *
 * web:   https://www.atv-systems.de
 * email: atv@atv-systems.de
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "K4200ModuleLptLibrary.h"
#include "K4200ModuleLptLibraryFunctions.h"

namespace module
{
    //-------------------------------------------------------------------------------------------------

    /// <summary>
    /// Python module method table.
    /// </summary>
    static PyMethodDef K4200ModuleLptLibraryMethods[] =
    {
        { "initialize",  K4200LptInitialize, METH_VARARGS, "Initializes the LPT library (loads the LPT library)." },
        { "test",  K4200LptTest, METH_VARARGS, "Python module test function. Has two floats as parameters and returns d1 * d2, d1 + d2." },
        { "devclr",  K4200Lpt_devclr, METH_VARARGS, "This command sets all sources to a zero state." },
        { "devint",  K4200Lpt_devint, METH_VARARGS, "This command resets all active instruments in the system to their default states." },
        { "clrscn",  K4200Lpt_clrscn, METH_VARARGS, "This command clears the measurement scan tables associated with a sweep." },
        { "delay",  K4200Lpt_delay, METH_VARARGS, "This command provides a user-programmable delay in a test sequence." },
        { "tstsel",  K4200Lpt_tstsel, METH_VARARGS, "This command enables or disables a test station." },
        { "setauto",  K4200Lpt_setauto, METH_VARARGS, "This command re-enables autoranging and cancels any previous rangeX command for the specified instrument." },
        { "pulse_init",  K4200Lpt_pulse_init, METH_VARARGS, "This command resets the pulse card to the default settings for the pulse mode that is presently selected." },
        { "cvu_custom_cable_comp",  K4200Lpt_cvu_custom_cable_comp, METH_VARARGS, "This command determines the delays needed to accommodate custom cable lengths." },
        { "pulse_halt",  K4200Lpt_pulse_halt, METH_VARARGS, "This command stops all pulse output from the pulse card." },
        { "rtfary",  K4200Lpt_rtfary, METH_VARARGS, "This command returns the force array determined by the instrument action." },
        { "forcei",  K4200Lpt_forcei, METH_VARARGS, "This command programs a sourcing instrument to generate a current at a specific level." },
        { "forcev",  K4200Lpt_forcev, METH_VARARGS, "This command programs a sourcing instrument to generate a voltage at a specific level." },
        { "limiti",  K4200Lpt_limiti, METH_VARARGS, "This command allows the programmer to specify a current limit other than the default limit of the instrument." },
        { "limitv",  K4200Lpt_limitv, METH_VARARGS, "This command allows the programmer to specify a voltage limit other than the default limit of the instrument." },
        { "rangei",  K4200Lpt_rangei, METH_VARARGS, "This command selects a range and prevents the selected instrument from autoranging." },
        { "rangev",  K4200Lpt_rangev, METH_VARARGS, "This command selects a range and prevents the selected instrument from autoranging." },
        { "lorangei",  K4200Lpt_lorangei, METH_VARARGS, "This command defines the bottom autorange limit." },
        { "lorangev",  K4200Lpt_lorangev, METH_VARARGS, "This command defines the bottom autorange limit." },
        { "setfreq",  K4200Lpt_setfreq, METH_VARARGS, "This command sets the frequency for the AC drive." },
        { "setlevel",  K4200Lpt_setlevel, METH_VARARGS, "This command sets the AC drive voltage level." },
        { "pulse_period",  K4200Lpt_pulse_period, METH_VARARGS, "This command sets the period for pulse output." },
        { "measi",  K4200Lpt_measi, METH_VARARGS, "This command allows the measurement of current." },
        { "measv",  K4200Lpt_measv, METH_VARARGS, "This command allows the measurement of voltage." },
        { "meast",  K4200Lpt_meast, METH_VARARGS, "This command allows the measurement of time." },
        { "measf",  K4200Lpt_measf, METH_VARARGS, "This command returns the frequency sourced during a single measurement." },
        { "intgi",  K4200Lpt_intgi, METH_VARARGS, "This command performs current measurements averaged over a user-defined period (usually, one AC line cycle)." },
        { "intgv",  K4200Lpt_intgv, METH_VARARGS, "This command performs voltage measurements averaged over a user-defined period (usually, one AC line cycle)." },
        { "smeasi",  K4200Lpt_smeasi, METH_VARARGS, "This command allows a number of measurements to be made by a specified instrument during a sweepX command. The results of the measurements are stored in the defined array." },
        { "smeasv",  K4200Lpt_smeasv, METH_VARARGS, "This command allows a number of measurements to be made by a specified instrument during a sweepX command. The results of the measurements are stored in the defined array." },
        { "smeast",  K4200Lpt_smeast, METH_VARARGS, "This command allows a number of measurements to be made by a specified instrument during a sweepX command. The results of the measurements are stored in the defined array." },
        { "smeasf",  K4200Lpt_smeasf, METH_VARARGS, "This command returns the frequencies used for a sweep." },
        { "sintgi",  K4200Lpt_sintgi, METH_VARARGS, "This command makes an integrated measurement for every point in a sweep." },
        { "sintgv",  K4200Lpt_sintgv, METH_VARARGS, "This command makes an integrated measurement for every point in a sweep." },
        { "adelay",  K4200Lpt_adelay, METH_VARARGS, "This command specifies an array of delay points to use with asweepX command calls." },
        { "pg2_init",  K4200Lpt_pg2_init, METH_VARARGS, "This command resets the pulse card to the specified pulse mode (standard, full arb, or Segment Arb) and its default conditions." },
        { "pulse_trig_output",  K4200Lpt_pulse_trig_output, METH_VARARGS, "This command sets the output trigger on or off." },
        { "pulse_trig",  K4200Lpt_pulse_trig, METH_VARARGS, "This command selects the trigger mode (continuous, burst, or trigger burst) and initiates the start of pulse output or arms the pulse card." },
        { "pulse_trig_polarity",  K4200Lpt_pulse_trig_polarity, METH_VARARGS, "This command sets the polarity (positive or negative) of the pulse card output trigger." },
        { "pulse_trig_source",  K4200Lpt_pulse_trig_source, METH_VARARGS, "This command sets the trigger source." },
        { "pulse_float",  K4200Lpt_pulse_float, METH_VARARGS, "" },
        { "getinstname",  K4200Lpt_getinstname, METH_VARARGS, "This command returns the instrument name string from the instrument identifier (ID)." },
        { "getinstid",  K4200Lpt_getinstid, METH_VARARGS, "This command returns the instrument identifier (ID) from the instrument name string." },
        { "setmode",  K4200Lpt_setmode, METH_VARARGS, "This command sets instrument-specific operating mode parameters." },
        { "pulse_range",  K4200Lpt_pulse_range, METH_VARARGS, "This command sets a pulse card channel for low voltage (fast speed) or high voltage (slow speed)." },
        { "pulse_rise",  K4200Lpt_pulse_rise, METH_VARARGS, "This command sets the rise transition time for the pulse card pulse output" },
        { "pulse_fall",  K4200Lpt_pulse_fall, METH_VARARGS, "This command sets the fall transition time for the pulse output." },
        { "pulse_width",  K4200Lpt_pulse_width, METH_VARARGS, "This command sets the pulse width for pulse output." },
        { "pulse_vhigh",  K4200Lpt_pulse_vhigh, METH_VARARGS, "This command sets the pulse voltage high level." },
        { "pulse_vlow",  K4200Lpt_pulse_vlow, METH_VARARGS, "This command sets the pulse voltage low value." },
        { "pulse_delay",  K4200Lpt_pulse_delay, METH_VARARGS, "This command sets the delay time from the trigger to when the pulse output starts." },
        { "pulse_current_limit",  K4200Lpt_pulse_current_limit, METH_VARARGS, "This command sets the current limit of the pulse card." },
        { "pulse_load",  K4200Lpt_pulse_load, METH_VARARGS, "This command sets the output impedance for the load (DUT)." },
        { "pulse_dc_output",  K4200Lpt_pulse_dc_output, METH_VARARGS, "This command selects the DC output mode and sets the voltage level." },
        { "pulse_output",  K4200Lpt_pulse_output, METH_VARARGS, "This command sets the pulse output of a pulse card channel on or off." },
        { "pulse_output_mode",  K4200Lpt_pulse_output_mode, METH_VARARGS, "This command sets the pulse output mode of a pulse card channel." },
        { "pulse_burst_count",  K4200Lpt_pulse_burst_count, METH_VARARGS, "For the burst mode, this command sets the number of pulses to output during a burst sequence." },
        { "getstatus",  K4200Lpt_getstatus, METH_VARARGS, "This command returns various parameters pertaining to the state of the 4210-CVU." },
        { "kibcmd",  K4200Lpt_kibcmd, METH_VARARGS, "This command enables universal, addressed, and unaddressed GPIB bus commands to be sent through the GPIB interface." },
        { "kibspl",  K4200Lpt_kibspl, METH_VARARGS, "This command serial polls an instrument connected to the GPIB interface." },
        { "kspsnd",  K4200Lpt_kspsnd, METH_VARARGS, "This command sends a device-dependent command to an instrument attached to a RS-232 serial port." },
        { "pulse_ssrc",  K4200Lpt_pulse_ssrc, METH_VARARGS, "This command controls the high-endurance output relay (HEOR) for each output channel of the PGU." },
        { "pulse_getcal",  K4200Lpt_pulse_getcal, METH_VARARGS, "" },
        { "asweepv",  K4200Lpt_asweepv, METH_VARARGS, "This command generates a waveform based on a user-defined forcing array (logarithmic sweep or other custom forcing commands)." },
        { "asweepi",  K4200Lpt_asweepi, METH_VARARGS, "This command generates a waveform based on a user-defined forcing array (logarithmic sweep or other custom forcing commands)." },
        { "measz",  K4200Lpt_measz, METH_VARARGS, "This command makes an impedance measurement." },
        { "smeasz",  K4200Lpt_smeasz, METH_VARARGS, "This command performs impedance measurements for a sweep." },
        { "sweepi",  K4200Lpt_sweepi, METH_VARARGS, "This command generates a ramp consisting of ascending or descending currents. The sweep consists of a sequence of steps, each with a user - specified duration." },
        { "sweepv",  K4200Lpt_sweepv, METH_VARARGS, "This command generates a ramp consisting of ascending or descending voltages. The sweep consists of a sequence of steps, each with a user - specified duration." },
        { "dsweepv",  K4200Lpt_dsweepv, METH_VARARGS, "This command performs a dual linear staircase voltage sweep." },
        { "sweepf",  K4200Lpt_sweepf, METH_VARARGS, "This command performs a frequency sweep." },
        { "dsweepf",  K4200Lpt_dsweepf, METH_VARARGS, "This command performs a dual frequency sweep." },
        { "kibsnd",  K4200Lpt_kibsnd, METH_VARARGS, "This command sends a device-dependent command to an instrument connected to the GPIB interface." },
        { "bsweepi",  K4200Lpt_bsweepi, METH_VARARGS, "This command supplies a series of ascending or descending currents and shuts down the source when a trigger condition is encountered." },
        { "bsweepv",  K4200Lpt_bsweepv, METH_VARARGS, "This command supplies a series of ascending or descending voltages and shuts down the source when a trigger condition is encountered." },
        { "kspcfg",  K4200Lpt_kspcfg, METH_VARARGS, "This command configures and allocates a serial port for RS-232 communications." },
        { "ksprcv",  K4200Lpt_ksprcv, METH_VARARGS, "This command reads data from an instrument connected to a serial port." },
        { "kibrcv",  K4200Lpt_kibrcv, METH_VARARGS, "This command reads a device-dependent string from an instrument connected to the GPIB interface." },
        { nullptr, nullptr, 0, nullptr}             // end of methods
    };

    //-------------------------------------------------------------------------------------------------

    /// <summary>
    /// Python module definition.
    /// </summary>
    static struct PyModuleDef K4200ModuleLptLibrary =
    {
        PyModuleDef_HEAD_INIT,
        "k4200lptlibrary",                          // name of module
        "Keithley 4200 LPT library functions.",     // module documentation, may be NULL
        -1,                                         // size of per-interpreter state of the module, or -1 if the module keeps state in global variables.
        K4200ModuleLptLibraryMethods
    };

    //-------------------------------------------------------------------------------------------------

    /// <summary>
    /// Keithley 4200 LPT library exception for error reporting.
    /// </summary>
    static PyObject *K4200LptLibraryError;

    PyObject *GetK4200LptLibraryError()
    {
        return K4200LptLibraryError;
    }

} // namespace module

//-------------------------------------------------------------------------------------------------

extern "C"
{
    /// <summary>
    /// Python module initialization.
    /// </summary>
    /// <returns>The python module.</returns>
    PyMODINIT_FUNC PyInit_k4200lptlibrary()
    {
        const auto m = PyModule_Create(&module::K4200ModuleLptLibrary);
        if (m == nullptr)
            return nullptr;

        // define own exception for this module
        module::K4200LptLibraryError = PyErr_NewException("k4200lptlibrary.error", nullptr, nullptr);
        Py_XINCREF(module::K4200LptLibraryError);

        if (PyModule_AddObject(m, "error", module::K4200LptLibraryError) < 0)
        {
            Py_XDECREF(module::K4200LptLibraryError);
            Py_CLEAR(module::K4200LptLibraryError);
            Py_DECREF(m);
            return nullptr;
        }

        return m;
    }
}

//-------------------------------------------------------------------------------------------------


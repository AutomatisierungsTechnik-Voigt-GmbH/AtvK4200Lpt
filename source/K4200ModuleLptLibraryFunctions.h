#pragma once

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

#define PY_SSIZE_T_CLEAN
#include <Python.h>

namespace module
{
    // The python module wrapper functions for the K4200 lpt library functions.

    /// <summary>
    /// Loads and initializes the lpt library to use it in python.
    /// </summary>
    PyObject * K4200LptInitialize(PyObject *self, PyObject *args);

    /// <summary>
    /// Python module test function.
    /// Has two floats as parameters and returns d1 * d2, d1 + d2.
    /// </summary>
    PyObject * K4200LptTest(PyObject *self, PyObject *args);

    // The lpt library functions. (see K4200 reference manual for function and parameter description.)

    PyObject * K4200Lpt_devclr(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_devint(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_clrscn(PyObject *self, PyObject *args);

    PyObject * K4200Lpt_delay(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_tstsel(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_setauto(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_pulse_init(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_cvu_custom_cable_comp(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_pulse_halt(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_rtfary(PyObject *self, PyObject *args);

    PyObject * K4200Lpt_forcei(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_forcev(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_limiti(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_limitv(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_rangei(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_rangev(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_lorangei(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_lorangev(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_setfreq(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_setlevel(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_pulse_period(PyObject *self, PyObject *args);

    PyObject * K4200Lpt_measi(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_measv(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_meast(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_measf(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_intgi(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_intgv(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_smeasi(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_smeasv(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_smeast(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_smeasf(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_sintgi(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_sintgv(PyObject *self, PyObject *args);

    PyObject * K4200Lpt_adelay(PyObject *self, PyObject *args);

    PyObject * K4200Lpt_pg2_init(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_pulse_trig_output(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_pulse_trig(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_pulse_trig_polarity(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_pulse_trig_source(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_pulse_float(PyObject *self, PyObject *args);

    PyObject * K4200Lpt_getinstname(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_getinstid(PyObject *self, PyObject *args);

    PyObject * K4200Lpt_setmode(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_pulse_range(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_pulse_rise(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_pulse_fall(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_pulse_width(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_pulse_vhigh(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_pulse_vlow(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_pulse_delay(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_pulse_current_limit(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_pulse_load(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_pulse_dc_output(PyObject *self, PyObject *args);

    PyObject * K4200Lpt_pulse_output(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_pulse_output_mode(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_pulse_burst_count(PyObject *self, PyObject *args);

    PyObject * K4200Lpt_getstatus(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_kibcmd(PyObject *self, PyObject *args);

    PyObject * K4200Lpt_kibspl(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_kspsnd(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_pulse_ssrc(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_pulse_getcal(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_asweepv(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_asweepi(PyObject *self, PyObject *args);

    PyObject * K4200Lpt_measz(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_smeasz(PyObject *self, PyObject *args);

    PyObject * K4200Lpt_sweepi(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_sweepv(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_dsweepv(PyObject *self, PyObject *args);

    PyObject * K4200Lpt_sweepf(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_dsweepf(PyObject *self, PyObject *args);

    PyObject * K4200Lpt_kibsnd(PyObject *self, PyObject *args);

    PyObject * K4200Lpt_bsweepi(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_bsweepv(PyObject *self, PyObject *args);

    PyObject * K4200Lpt_kspcfg(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_ksprcv(PyObject *self, PyObject *args);
    PyObject * K4200Lpt_kibrcv(PyObject *self, PyObject *args);

} // namespace module


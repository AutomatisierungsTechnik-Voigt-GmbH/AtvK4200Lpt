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

#include "K4200LptLibrary.h"

#include "DllLoader.h"

namespace k4200
{

    //-----------------------------------------------------------------------------

    int32_t(WINAPI *f_devclr)() = nullptr;
    int32_t(WINAPI *f_devint)() = nullptr;
    int32_t(WINAPI *f_clrscn)() = nullptr;

    //-----------------------------------------------------------------------------

    int32_t(WINAPI *f_delay)(int32_t) = nullptr;
    int32_t(WINAPI *f_tstsel)(int32_t teststation) = nullptr;
    int32_t(WINAPI *f_setauto)(int32_t) = nullptr;
    int32_t(WINAPI *f_pulse_init)(int32_t instr_id) = nullptr;
    int32_t(WINAPI *f_cvu_custom_cable_comp)(int32_t instr_id) = nullptr;
    int32_t(WINAPI *f_pulse_halt)(int32_t instr_id) = nullptr;

    int32_t(WINAPI *f_rtfary)(double *forceArray) = nullptr;

    //-----------------------------------------------------------------------------

    int32_t(WINAPI *f_forcei)(int32_t, double) = nullptr;
    int32_t(WINAPI *f_forcev)(int32_t, double) = nullptr;
    int32_t(WINAPI *f_limiti)(int32_t, double) = nullptr;
    int32_t(WINAPI *f_limitv)(int32_t, double) = nullptr;
    int32_t(WINAPI *f_rangei)(int32_t, double) = nullptr;
    int32_t(WINAPI *f_rangev)(int32_t, double) = nullptr;
    int32_t(WINAPI *f_lorangei)(int32_t, double) = nullptr;
    int32_t(WINAPI *f_lorangev)(int32_t, double) = nullptr;
    int32_t(WINAPI *f_setfreq)(int32_t instid, double frequency) = nullptr;
    int32_t(WINAPI *f_setlevel)(int32_t instid, double signalLevel) = nullptr;
    int32_t(WINAPI *f_pulse_period)(int32_t instr_id, double period) = nullptr;

    int32_t(WINAPI *f_measi)(int32_t, double *) = nullptr;
    int32_t(WINAPI *f_measv)(int32_t, double *) = nullptr;
    int32_t(WINAPI *f_meast)(int32_t, double *) = nullptr;
    int32_t(WINAPI *f_measf)(int32_t, double *) = nullptr;
    int32_t(WINAPI *f_intgi)(int32_t, double *) = nullptr;
    int32_t(WINAPI *f_intgv)(int32_t, double *) = nullptr;
    int32_t(WINAPI *f_smeasi)(int32_t, double *) = nullptr;
    int32_t(WINAPI *f_smeasv)(int32_t, double *) = nullptr;
    int32_t(WINAPI *f_smeast)(int32_t, double *) = nullptr;
    int32_t(WINAPI *f_smeasf)(int32_t, double *) = nullptr;
    int32_t(WINAPI *f_sintgi)(int32_t, double *) = nullptr;
    int32_t(WINAPI *f_sintgv)(int32_t, double *) = nullptr;
    int32_t(WINAPI *f_adelay)(int32_t delaypoints, double *delayarray) = nullptr;

    int32_t(WINAPI *f_pg2_init)(int32_t instr_id, int32_t mode) = nullptr;
    int32_t(WINAPI *f_pulse_trig_output)(int32_t instr_id, int32_t state) = nullptr;
    int32_t(WINAPI *f_pulse_trig)(int32_t instr_id, int32_t mode) = nullptr;
    int32_t(WINAPI *f_pulse_trig_polarity)(int32_t instr_id, int32_t polarity) = nullptr;
    int32_t(WINAPI *f_pulse_trig_source)(int32_t instr_id, int32_t source) = nullptr;
    int32_t(WINAPI *f_pulse_float)(int32_t instr_id, uint32_t enable) = nullptr;

    int32_t(WINAPI *f_getinstname)(int32_t instr_id, char *idstring) = nullptr;

    int32_t(WINAPI *f_getinstid)(const char *idstring, int32_t *instr_id) = nullptr;

    //-----------------------------------------------------------------------------

    int32_t(WINAPI *f_setmode)(int32_t, int32_t, double) = nullptr;
    int32_t(WINAPI *f_pulse_range)(int32_t instr_id, int32_t chan, double range) = nullptr;
    int32_t(WINAPI *f_pulse_rise)(int32_t instr_id, int32_t chan, double riset) = nullptr;
    int32_t(WINAPI *f_pulse_fall)(int32_t instr_id, int32_t chan, double fallt) = nullptr;
    int32_t(WINAPI *f_pulse_width)(int32_t instr_id, int32_t chan, double width) = nullptr;
    int32_t(WINAPI *f_pulse_vhigh)(int32_t instr_id, int32_t chan, double vhigh) = nullptr;
    int32_t(WINAPI *f_pulse_vlow)(int32_t instr_id, int32_t chan, double vlow) = nullptr;
    int32_t(WINAPI *f_pulse_delay)(int32_t instr_id, int32_t chan, double delay) = nullptr;
    int32_t(WINAPI *f_pulse_current_limit)(int32_t instr_id, int32_t chan, double ilimit) = nullptr;
    int32_t(WINAPI *f_pulse_load)(int32_t instr_id, int32_t chan, double load) = nullptr;
    int32_t(WINAPI *f_pulse_dc_output)(int32_t instr_id, int32_t chan, double dc_level) = nullptr;

    int32_t(WINAPI *f_pulse_output)(int32_t instr_id, int32_t chan, int32_t state) = nullptr;
    int32_t(WINAPI *f_pulse_output_mode)(int32_t instr_id, int32_t chan, int32_t mode) = nullptr;
    int32_t(WINAPI *f_pulse_burst_count)(int32_t instr_id, int32_t chan, uint32_t count) = nullptr;

    int32_t(WINAPI *f_getstatus)(int32_t instid, int32_t parameter, double *value) = nullptr;

    int32_t(WINAPI *f_kibcmd)(uint32_t timeout, uint32_t numbytes, const char *cmdbuffer) = nullptr;

    //-----------------------------------------------------------------------------

    int32_t(WINAPI *f_kibspl)(int32_t pri_addr, int32_t sec_addr, uint32_t timeout, int32_t *statusbyte) = nullptr;

    int32_t(WINAPI *f_kspsnd)(int32_t port, double timeout, int32_t cmdlen, const char *cmd) = nullptr;

    int32_t(WINAPI *f_pulse_ssrc)(int32_t instr_id, int32_t channel, int32_t state, int32_t ctrl) = nullptr;

    int32_t(WINAPI *f_pulse_getcal)(int32_t instr_id, int32_t channel, int32_t index, double *calval) = nullptr;

    int32_t(WINAPI *f_asweepv)(int32_t instr_id, int32_t numberOfPoints, double delayTime, double *forceArray) = nullptr;
    int32_t(WINAPI *f_asweepi)(int32_t instr_id, int32_t numberOfPoints, double delayTime, double *forceArray) = nullptr;

    //-----------------------------------------------------------------------------

    int32_t(WINAPI *f_measz)(int32_t instid, int32_t model, int32_t speed, double *result1, double *result2) = nullptr;
    int32_t(WINAPI *f_smeasz)(int32_t instr_id, int32_t model, int32_t speed, double *res1, double *res2) = nullptr;

    int32_t(WINAPI *f_sweepi)(int32_t instid, double startval, double endval, int32_t stepno, double stepdelay) = nullptr;
    int32_t(WINAPI *f_sweepv)(int32_t instid, double startval, double endval, int32_t stepno, double stepdelay) = nullptr;
    int32_t(WINAPI *f_dsweepv)(int32_t instid, double startval, double endval, int32_t stepno, double stepdelay) = nullptr;

    int32_t(WINAPI *f_sweepf)(int32_t instid, double startf, double stopf, int32_t *NumPts, double delaytime) = nullptr;
    int32_t(WINAPI *f_dsweepf)(int32_t instid, double startf, double stopf, int32_t *NumPts, double delaytime) = nullptr;

    int32_t(WINAPI *f_kibsnd)(int32_t pri_addr, int32_t sec_addr, uint32_t timeout, uint32_t send_len, const char *send_buff) = nullptr;

    //-----------------------------------------------------------------------------

    int32_t(WINAPI *f_bsweepi)(int32_t instr_id, double startval, double endval, int32_t num_points, double delay_time, double *result) = nullptr;
    int32_t(WINAPI *f_bsweepv)(int32_t instr_id, double startval, double endval, int32_t num_points, double delay_time, double *result) = nullptr;

    int32_t(WINAPI *f_kspcfg)(int32_t port, int32_t baud, int32_t databits, int32_t parity, int32_t stopbits, int32_t flowctl) = nullptr;

    int32_t(WINAPI *f_ksprcv)(int32_t port, char terminator, double timeout, int32_t rcvsize, int32_t *rcv_len, char *rcv_buffer) = nullptr;

    //-----------------------------------------------------------------------------

    int32_t(WINAPI *f_kibrcv)(int32_t pri_addr, int32_t sec_addr, char term, uint32_t timeout, uint32_t rcv_size, uint32_t *rcv_len, char *rcv_buff) = nullptr;

    //-----------------------------------------------------------------------------

    static utils::DllLoader _lptLibrary;

    /// <summary>
    /// Checks if is LPT library is initialized (loaded).
    /// </summary>
    bool IsK4200LptLibraryInitialized()
    {
        return _lptLibrary.IsLoaded();
    }

    /// <summary>
    /// Initializes the LPT library (loads the library and queries the function pointers).
    /// </summary>
    void K4200LptLibraryInitialize()
    {
        if (IsK4200LptLibraryInitialized())
            return;

        _lptLibrary.Load("lptlib.dll");

        _lptLibrary.GetDllFunc(f_devclr, "devclr");
        _lptLibrary.GetDllFunc(f_devint, "devint");
        _lptLibrary.GetDllFunc(f_delay, "delay");
        _lptLibrary.GetDllFunc(f_getinstid, "getinstid");
        _lptLibrary.GetDllFunc(f_getinstname, "getinstname");

        _lptLibrary.GetDllFunc(f_forcei, "forcei");
        _lptLibrary.GetDllFunc(f_forcev, "forcev");

        _lptLibrary.GetDllFunc(f_limiti, "limiti");
        _lptLibrary.GetDllFunc(f_limitv, "limitv");

        _lptLibrary.GetDllFunc(f_measi, "measi");
        _lptLibrary.GetDllFunc(f_measv, "measv");
        _lptLibrary.GetDllFunc(f_meast, "meast");
        _lptLibrary.GetDllFunc(f_measf, "measf");
        _lptLibrary.GetDllFunc(f_measz, "measz");
        _lptLibrary.GetDllFunc(f_intgi, "intgi");
        _lptLibrary.GetDllFunc(f_intgv, "intgv");

        _lptLibrary.GetDllFunc(f_rangei, "rangei");
        _lptLibrary.GetDllFunc(f_rangev, "rangev");
        _lptLibrary.GetDllFunc(f_lorangei, "lorangei");
        _lptLibrary.GetDllFunc(f_lorangev, "lorangev");

        _lptLibrary.GetDllFunc(f_setauto, "setauto");
        _lptLibrary.GetDllFunc(f_setmode, "setmode");
        _lptLibrary.GetDllFunc(f_tstsel, "tstsel");

        _lptLibrary.GetDllFunc(f_smeasi, "smeasi");
        _lptLibrary.GetDllFunc(f_smeasv, "smeasv");
        _lptLibrary.GetDllFunc(f_smeast, "smeast");
        _lptLibrary.GetDllFunc(f_smeasf, "smeasf");
        _lptLibrary.GetDllFunc(f_smeasz, "smeasz");
        _lptLibrary.GetDllFunc(f_sintgv, "sintgv");
        _lptLibrary.GetDllFunc(f_sintgi, "sintgi");
        _lptLibrary.GetDllFunc(f_rtfary, "rtfary");

        _lptLibrary.GetDllFunc(f_sweepi, "sweepi");
        _lptLibrary.GetDllFunc(f_sweepv, "sweepv");
        _lptLibrary.GetDllFunc(f_sweepf, "sweepf");
        _lptLibrary.GetDllFunc(f_dsweepf, "dsweepf");
        _lptLibrary.GetDllFunc(f_dsweepv, "dsweepv");

        _lptLibrary.GetDllFunc(f_kibspl, "kibspl");
        _lptLibrary.GetDllFunc(f_kibsnd, "kibsnd");
        _lptLibrary.GetDllFunc(f_kibrcv, "kibrcv");
        _lptLibrary.GetDllFunc(f_kibcmd, "kibcmd");

        _lptLibrary.GetDllFunc(f_kspcfg, "kspcfg");
        _lptLibrary.GetDllFunc(f_ksprcv, "ksprcv");
        _lptLibrary.GetDllFunc(f_kspsnd, "kspsnd");

        _lptLibrary.GetDllFunc(f_clrscn, "clrscn");
        _lptLibrary.GetDllFunc(f_getstatus, "getstatus");
        _lptLibrary.GetDllFunc(f_setfreq, "setfreq");
        _lptLibrary.GetDllFunc(f_setlevel, "setlevel");

        _lptLibrary.GetDllFunc(f_pg2_init, "pg2_init");
        _lptLibrary.GetDllFunc(f_pulse_init, "pulse_init");
        _lptLibrary.GetDllFunc(f_pulse_load, "pulse_load");
        _lptLibrary.GetDllFunc(f_pulse_range, "pulse_range");
        _lptLibrary.GetDllFunc(f_pulse_current_limit, "pulse_current_limit");
        _lptLibrary.GetDllFunc(f_pulse_rise, "pulse_rise");
        _lptLibrary.GetDllFunc(f_pulse_fall, "pulse_fall");
        _lptLibrary.GetDllFunc(f_pulse_halt, "pulse_halt");
        _lptLibrary.GetDllFunc(f_pulse_vlow, "pulse_vlow");
        _lptLibrary.GetDllFunc(f_pulse_vhigh, "pulse_vhigh");
        _lptLibrary.GetDllFunc(f_pulse_period, "pulse_period");
        _lptLibrary.GetDllFunc(f_pulse_width, "pulse_width");
        _lptLibrary.GetDllFunc(f_pulse_delay, "pulse_delay");
        _lptLibrary.GetDllFunc(f_pulse_burst_count, "pulse_burst_count");
        _lptLibrary.GetDllFunc(f_pulse_trig_output, "pulse_trig_output");
        _lptLibrary.GetDllFunc(f_pulse_output, "pulse_output");
        _lptLibrary.GetDllFunc(f_pulse_output_mode, "pulse_output_mode");
        _lptLibrary.GetDllFunc(f_pulse_trig, "pulse_trig");
        _lptLibrary.GetDllFunc(f_pulse_trig_polarity, "pulse_trig_polarity");
        _lptLibrary.GetDllFunc(f_pulse_trig_source, "pulse_trig_source");
        _lptLibrary.GetDllFunc(f_pulse_dc_output, "pulse_dc_output");
        _lptLibrary.GetDllFunc(f_pulse_float, "pulse_float");
        _lptLibrary.GetDllFunc(f_pulse_ssrc, "pulse_ssrc");
        _lptLibrary.GetDllFunc(f_pulse_getcal, "pulse_getcal");

        _lptLibrary.GetDllFunc(f_adelay, "adelay");
        _lptLibrary.GetDllFunc(f_asweepv, "asweepv");
        _lptLibrary.GetDllFunc(f_asweepi, "asweepi");
        _lptLibrary.GetDllFunc(f_bsweepi, "bsweepi");
        _lptLibrary.GetDllFunc(f_bsweepv, "bsweepv");
        _lptLibrary.GetDllFunc(f_cvu_custom_cable_comp, "cvu_custom_cable_comp");
    }

    //-----------------------------------------------------------------------------

} // namespace k4200

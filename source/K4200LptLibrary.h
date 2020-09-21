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

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <stdint.h>

namespace k4200
{

    /// <summary>
    /// Initializes the LPT library (loads the library and queries the function pointers).
    /// </summary>
    void K4200LptLibraryInitialize();

    /// <summary>
    /// Checks if is LPT library is initialized (loaded).
    /// </summary>
    bool IsK4200LptLibraryInitialized();

    // K4200 LPT library function pointers.

    extern int32_t(WINAPI *f_devclr)();
    extern int32_t(WINAPI *f_devint)();
    extern int32_t(WINAPI *f_delay)(int32_t);
    extern int32_t(WINAPI *f_getinstid)(const char *idstring, int32_t *instr_id);
    extern int32_t(WINAPI *f_getinstname)(int32_t instr_id, char *idstring);

    extern int32_t(WINAPI *f_forcei)(int32_t, double);
    extern int32_t(WINAPI *f_forcev)(int32_t, double);

    extern int32_t(WINAPI *f_limiti)(int32_t, double);
    extern int32_t(WINAPI *f_limitv)(int32_t, double);

    extern int32_t(WINAPI *f_measi)(int32_t, double *);
    extern int32_t(WINAPI *f_measv)(int32_t, double *);
    extern int32_t(WINAPI *f_meast)(int32_t, double *);
    extern int32_t(WINAPI *f_measf)(int32_t, double *);
    extern int32_t(WINAPI *f_measz)(int32_t instid, int32_t model, int32_t speed, double *result1, double *result2);
    extern int32_t(WINAPI *f_intgi)(int32_t, double *);
    extern int32_t(WINAPI *f_intgv)(int32_t, double *);

    extern int32_t(WINAPI *f_rangei)(int32_t, double);
    extern int32_t(WINAPI *f_rangev)(int32_t, double);
    extern int32_t(WINAPI *f_lorangei)(int32_t, double);
    extern int32_t(WINAPI *f_lorangev)(int32_t, double);

    extern int32_t(WINAPI *f_setauto)(int32_t);
    extern int32_t(WINAPI *f_setmode)(int32_t, int32_t, double);
    extern int32_t(WINAPI *f_tstsel)(int32_t teststation);

    extern int32_t(WINAPI *f_smeasi)(int32_t, double *);
    extern int32_t(WINAPI *f_smeasv)(int32_t, double *);
    extern int32_t(WINAPI *f_smeast)(int32_t, double *);
    extern int32_t(WINAPI *f_smeasf)(int32_t, double *);
    extern int32_t(WINAPI *f_smeasz)(int32_t instr_id, int32_t model, int32_t speed, double *res1, double *res2);
    extern int32_t(WINAPI *f_sintgi)(int32_t, double *);
    extern int32_t(WINAPI *f_sintgv)(int32_t, double *);
    extern int32_t(WINAPI *f_rtfary)(double *forceArray);

    extern int32_t(WINAPI *f_sweepi)(int32_t instid, double startval, double endval, int32_t stepno, double stepdelay);
    extern int32_t(WINAPI *f_sweepv)(int32_t instid, double startval, double endval, int32_t stepno, double stepdelay);
    extern int32_t(WINAPI *f_sweepf)(int32_t instid, double startf, double stopf, int32_t *NumPts, double delaytime);
    extern int32_t(WINAPI *f_dsweepf)(int32_t instid, double startf, double stopf, int32_t *NumPts, double delaytime);
    extern int32_t(WINAPI *f_dsweepv)(int32_t instid, double startval, double endval, int32_t stepno, double stepdelay);

    extern int32_t(WINAPI *f_kibspl)(int32_t pri_addr, int32_t sec_addr, uint32_t timeout, int32_t *statusbyte);
    extern int32_t(WINAPI *f_kibsnd)(int32_t pri_addr, int32_t sec_addr, uint32_t timeout, uint32_t send_len, const char *send_buff);
    extern int32_t(WINAPI *f_kibrcv)(int32_t pri_addr, int32_t sec_addr, char term, uint32_t timeout, uint32_t rcv_size, uint32_t *rcv_len, char *rcv_buff);
    extern int32_t(WINAPI *f_kibcmd)(uint32_t timeout, uint32_t numbytes, const char *cmdbuffer);

    extern int32_t(WINAPI *f_kspcfg)(int32_t port, int32_t baud, int32_t databits, int32_t parity, int32_t stopbits, int32_t flowctl);
    extern int32_t(WINAPI *f_ksprcv)(int32_t port, char terminator, double timeout, int32_t rcvsize, int32_t *rcv_len, char *rcv_buffer);
    extern int32_t(WINAPI *f_kspsnd)(int32_t port, double timeout, int32_t cmdlen, const char *cmd);

    extern int32_t(WINAPI *f_clrscn)();
    extern int32_t(WINAPI *f_getstatus)(int32_t instid, int32_t parameter, double *value);
    extern int32_t(WINAPI *f_setfreq)(int32_t instid, double frequency);
    extern int32_t(WINAPI *f_setlevel)(int32_t instid, double signalLevel);

    extern int32_t(WINAPI *f_pg2_init)(int32_t instr_id, int32_t mode);

    extern int32_t(WINAPI *f_pulse_init)(int32_t instr_id);
    extern int32_t(WINAPI *f_pulse_output)(int32_t instr_id, int32_t chan, int32_t state);
    extern int32_t(WINAPI *f_pulse_output_mode)(int32_t instr_id, int32_t chan, int32_t mode);
    extern int32_t(WINAPI *f_pulse_trig_output)(int32_t instr_id, int32_t state);
    extern int32_t(WINAPI *f_pulse_range)(int32_t instr_id, int32_t chan, double range);
    extern int32_t(WINAPI *f_pulse_period)(int32_t instr_id, double period);
    extern int32_t(WINAPI *f_pulse_rise)(int32_t instr_id, int32_t chan, double riset);
    extern int32_t(WINAPI *f_pulse_fall)(int32_t instr_id, int32_t chan, double fallt);
    extern int32_t(WINAPI *f_pulse_width)(int32_t instr_id, int32_t chan, double width);
    extern int32_t(WINAPI *f_pulse_vhigh)(int32_t instr_id, int32_t chan, double vhigh);
    extern int32_t(WINAPI *f_pulse_vlow)(int32_t instr_id, int32_t chan, double vlow);
    extern int32_t(WINAPI *f_pulse_delay)(int32_t instr_id, int32_t chan, double delay);
    extern int32_t(WINAPI *f_pulse_trig)(int32_t instr_id, int32_t mode);
    extern int32_t(WINAPI *f_pulse_halt)(int32_t instr_id);
    extern int32_t(WINAPI *f_pulse_burst_count)(int32_t instr_id, int32_t chan, uint32_t count);
    extern int32_t(WINAPI *f_pulse_current_limit)(int32_t instr_id, int32_t chan, double ilimit);
    extern int32_t(WINAPI *f_pulse_load)(int32_t instr_id, int32_t chan, double load);
    extern int32_t(WINAPI *f_pulse_trig_polarity)(int32_t instr_id, int32_t polarity);
    extern int32_t(WINAPI *f_pulse_trig_source)(int32_t instr_id, int32_t source);
    extern int32_t(WINAPI *f_pulse_dc_output)(int32_t instr_id, int32_t chan, double dc_level);
    extern int32_t(WINAPI *f_pulse_float)(int32_t instr_id, uint32_t enable);
    extern int32_t(WINAPI *f_pulse_ssrc)(int32_t instr_id, int32_t channel, int32_t state, int32_t ctrl);
    extern int32_t(WINAPI *f_pulse_getcal)(int32_t instr_id, int32_t channel, int32_t index, double *calval);

    extern int32_t(WINAPI *f_adelay)(int32_t delaypoints, double *delayarray);
    extern int32_t(WINAPI *f_asweepi)(int32_t instr_id, int32_t numberOfPoints, double delayTime, double *forceArray);
    extern int32_t(WINAPI *f_asweepv)(int32_t instr_id, int32_t numberOfPoints, double delayTime, double *forceArray);
    extern int32_t(WINAPI *f_bsweepi)(int32_t instr_id, double startval, double endval, int32_t num_points, double delay_time, double *result);
    extern int32_t(WINAPI *f_bsweepv)(int32_t instr_id, double startval, double endval, int32_t num_points, double delay_time, double *result);
    extern int32_t(WINAPI *f_cvu_custom_cable_comp)(int32_t instr_id);

} // namespace k4200

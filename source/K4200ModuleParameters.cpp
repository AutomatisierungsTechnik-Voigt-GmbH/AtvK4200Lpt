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

#include "K4200ModuleParameters.h"
#include "K4200Parameters.h"
#include "PythonHelper.h"

using namespace helpers;
using namespace k4200;

namespace module
{

    //-------------------------------------------------------------------------------------------------
    // prototypes

    /// <summary>
    /// Adds all K4200 lpt library function parameters to a python object.
    /// </summary>
    /// <param name="m">The python object where the constants shall be added.</param>
    void K4200AddConstantsParameters(PyObject *m);

    //-------------------------------------------------------------------------------------------------

    /// <summary>
    /// Python module method table.
    /// </summary>
    static PyMethodDef K4200ModuleParametersMethods[] =
    {
        { nullptr, nullptr, 0, nullptr} // end of methods
    };

    //-------------------------------------------------------------------------------------------------

    /// <summary>
    /// Python module definition.
    /// </summary>
    static struct PyModuleDef K4200ModuleParameters =
    {
        PyModuleDef_HEAD_INIT,
        "k4200parameters",                                // name of module
        "Keithley 4200 LPT library parameter constants.", // module documentation, may be NULL
        -1,                                               // size of per-interpreter state of the module, or -1 if the module keeps state in global variables.
        K4200ModuleParametersMethods
    };

} // namespace module

//-------------------------------------------------------------------------------------------------

extern "C"
{
    /// <summary>
    /// Python module initialization.
    /// </summary>
    /// <returns>The python module.</returns>
    PyMODINIT_FUNC PyInit_k4200parameters()
    {
        const auto m = PyModule_Create(&module::K4200ModuleParameters);
        if (m == nullptr)
            return nullptr;

        module::K4200AddConstantsParameters(m);

        return m;
    }
}

//-------------------------------------------------------------------------------------------------

namespace module
{

    /// <summary>
    /// Adds all K4200 lpt library function parameters to a python object.
    /// </summary>
    /// <param name="m">The python object where the constants shall be added.</param>
    void K4200AddConstantsParameters(PyObject *m)
    {
        PyModule_AddIntConstant(m, "MINMODS", MINMODS);
        PyModule_AddIntConstant(m, "KI_TRIGMODE", KI_TRIGMODE);
        PyModule_AddIntConstant(m, "KI_AVGNUMBER", KI_AVGNUMBER);
        PyModule_AddIntConstant(m, "KI_AVGTIME", KI_AVGTIME);
        PyModule_AddIntConstant(m, "KI_REVIMEAS", KI_REVIMEAS);
        PyModule_AddIntConstant(m, "KI_MEASURE", KI_MEASURE);
        PyModule_AddIntConstant(m, "KI_IRANGE", KI_IRANGE);
        PyModule_AddIntConstant(m, "KI_QRANGE", KI_QRANGE);
        PyModule_AddIntConstant(m, "KI_ZEROCHECK", KI_ZEROCHECK);
        PyModule_AddIntConstant(m, "KI_ZEROCORRECT", KI_ZEROCORRECT);
        PyModule_AddIntConstant(m, "KI_SUPPRESS", KI_SUPPRESS);
        PyModule_AddIntConstant(m, "KI_VFORCE", KI_VFORCE);
        PyModule_AddIntConstant(m, "KI_SETTRIGA", KI_SETTRIGA);
        PyModule_AddIntConstant(m, "KI_SETTRIGB", KI_SETTRIGB);
        PyModule_AddIntConstant(m, "KI_CHANNELA", KI_CHANNELA);
        PyModule_AddIntConstant(m, "KI_CHANNELB", KI_CHANNELB);
        PyModule_AddIntConstant(m, "KI_SETGATE", KI_SETGATE);
        PyModule_AddIntConstant(m, "KI_POINTSWP", KI_POINTSWP);
        PyModule_AddIntConstant(m, "KI_SMARTCLEAR", KI_SMARTCLEAR);
        PyModule_AddIntConstant(m, "KI_PSCLEAR", KI_PSCLEAR);
        PyModule_AddIntConstant(m, "KI_EXTINPUT", KI_EXTINPUT);
        PyModule_AddIntConstant(m, "KI_SYNC", KI_SYNC);
        PyModule_AddIntConstant(m, "KI_FREQUENCY", KI_FREQUENCY);
        PyModule_AddIntConstant(m, "KI_READINGRATE", KI_READINGRATE);
        PyModule_AddIntConstant(m, "KI_WAVEFORM", KI_WAVEFORM);
        PyModule_AddIntConstant(m, "KI_STEPSIZE", KI_STEPSIZE);
        PyModule_AddIntConstant(m, "KI_TIMEDELAY", KI_TIMEDELAY);
        PyModule_AddIntConstant(m, "KI_INTGPLC", KI_INTGPLC);
        PyModule_AddIntConstant(m, "KI_AVGMODE", KI_AVGMODE);
        PyModule_AddIntConstant(m, "KI_CC_AUTO", KI_CC_AUTO);
        PyModule_AddIntConstant(m, "KI_CC_SRC_DLY", KI_CC_SRC_DLY);
        PyModule_AddIntConstant(m, "KI_CC_COMP_DLY", KI_CC_COMP_DLY);
        PyModule_AddIntConstant(m, "KI_CC_MEAS_DLY", KI_CC_MEAS_DLY);
        PyModule_AddIntConstant(m, "KI_RANGE_SETTLE", KI_RANGE_SETTLE);
        PyModule_AddIntConstant(m, "KI_RANGE_DELAY", KI_RANGE_DELAY);
        PyModule_AddIntConstant(m, "KI_LIM_INDCTR", KI_LIM_INDCTR);
        PyModule_AddIntConstant(m, "KI_MX_DEFMODE", KI_MX_DEFMODE);
        PyModule_AddIntConstant(m, "KI_HICURRENT", KI_HICURRENT);
        PyModule_AddIntConstant(m, "KI_IMTR", KI_IMTR);
        PyModule_AddIntConstant(m, "KI_VMTR", KI_VMTR);
        PyModule_AddIntConstant(m, "KI_LIM_MODE", KI_LIM_MODE);
        PyModule_AddIntConstant(m, "KI_OUTP_RELAY_STATE", KI_OUTP_RELAY_STATE);
        PyModule_AddIntConstant(m, "KI_SHIELD_RELAY_STATE", KI_SHIELD_RELAY_STATE);
        PyModule_AddIntConstant(m, "KI_OVP_LEVEL", KI_OVP_LEVEL);
        PyModule_AddIntConstant(m, "KI_AVM_LEVEL", KI_AVM_LEVEL);
        PyModule_AddIntConstant(m, "KI_TRIG_SRC_TLINK", KI_TRIG_SRC_TLINK);
        PyModule_AddIntConstant(m, "KI_INIT_IMM", KI_INIT_IMM);
        PyModule_AddIntConstant(m, "KI_I_READING", KI_I_READING);
        PyModule_AddIntConstant(m, "KI_V_READING", KI_V_READING);
        PyModule_AddIntConstant(m, "KI_RDG_STATUS", KI_RDG_STATUS);
        PyModule_AddIntConstant(m, "KI_PREAMP_PRESENT", KI_PREAMP_PRESENT);
        PyModule_AddIntConstant(m, "KI_OUTPUT_STANDBY", KI_OUTPUT_STANDBY);
        PyModule_AddIntConstant(m, "KI_TRIG_SRC_IMM", KI_TRIG_SRC_IMM);
        PyModule_AddIntConstant(m, "KI_SRC_VOLT_MODE", KI_SRC_VOLT_MODE);
        PyModule_AddIntConstant(m, "KI_DELAY_FACTOR", KI_DELAY_FACTOR);
        PyModule_AddIntConstant(m, "KI_SENSELO", KI_SENSELO);
        PyModule_AddIntConstant(m, "MAXMODS", MAXMODS);
        PyModule_AddIntConstant(m, "NUMMODS", NUMMODS);
        PyModule_AddIntConstant(m, "KI_OUTP_HIZ", KI_OUTP_HIZ);
        PyModule_AddIntConstant(m, "KI_OUTP_NORM", KI_OUTP_NORM);
        PyModule_AddIntConstant(m, "KI_OUTP_ZERO", KI_OUTP_ZERO);
        PyModule_AddIntConstant(m, "KI_REMOTE", KI_REMOTE);
        PyModule_AddIntConstant(m, "KI_LOCAL", KI_LOCAL);
        PyModule_AddIntConstant(m, "KI_AUTO", KI_AUTO);
        PyModule_AddIntConstant(m, "NUMMODVAL", NUMMODVAL);
        PyModule_AddIntConstant(m, "KI_IOFF", KI_IOFF);
        PyModule_AddIntConstant(m, "KI_ION", KI_ION);
        PyModule_AddIntConstant(m, "KI_IDCON", KI_IDCON);
        PyModule_AddIntConstant(m, "KI_IACON", KI_IACON);
        PyModule_AddIntConstant(m, "KI_IATTEN1X", KI_IATTEN1X);
        PyModule_AddIntConstant(m, "KI_IATTEN10X", KI_IATTEN10X);
        PyModule_AddIntConstant(m, "KI_IFLTON", KI_IFLTON);
        PyModule_AddIntConstant(m, "KI_IFLTOFF", KI_IFLTOFF);
        PyModule_AddIntConstant(m, "KI_IPSLOPE", KI_IPSLOPE);
        PyModule_AddIntConstant(m, "KI_INSLOPE", KI_INSLOPE);
        PyModule_AddIntConstant(m, "KI_IAMPS", KI_IAMPS);
        PyModule_AddIntConstant(m, "KI_ICOUL", KI_ICOUL);
        PyModule_AddIntConstant(m, "KI_IFREQA", KI_IFREQA);
        PyModule_AddIntConstant(m, "KI_IFREQB", KI_IFREQB);
        PyModule_AddIntConstant(m, "KI_IFREQC", KI_IFREQC);
        PyModule_AddIntConstant(m, "KI_IPERIODA", KI_IPERIODA);
        PyModule_AddIntConstant(m, "KI_IAVGPERIODA", KI_IAVGPERIODA);
        PyModule_AddIntConstant(m, "KI_ITIMEATOB", KI_ITIMEATOB);
        PyModule_AddIntConstant(m, "KI_IPULSEA", KI_IPULSEA);
        PyModule_AddIntConstant(m, "KI_ITOTABYB", KI_ITOTABYB);
        PyModule_AddIntConstant(m, "KI_ITOTCUM", KI_ITOTCUM);
        PyModule_AddIntConstant(m, "KI_IABSOLUTE", KI_IABSOLUTE);
        PyModule_AddIntConstant(m, "KI_INORMAL", KI_INORMAL);
        PyModule_AddIntConstant(m, "KI_IINTEGRATE", KI_IINTEGRATE);
        PyModule_AddIntConstant(m, "KI_IAVERAGE", KI_IAVERAGE);
        PyModule_AddIntConstant(m, "KI_IMEASX", KI_IMEASX);
        PyModule_AddIntConstant(m, "KI_IDC", KI_IDC);
        PyModule_AddIntConstant(m, "KI_ISINGLE_STAIR", KI_ISINGLE_STAIR);
        PyModule_AddIntConstant(m, "KI_IDOUBLE_STAIR", KI_IDOUBLE_STAIR);
        PyModule_AddIntConstant(m, "KI_IPULSE", KI_IPULSE);
        PyModule_AddIntConstant(m, "KI_IEXTERNAL", KI_IEXTERNAL);
        PyModule_AddIntConstant(m, "KI_ISTAIR", KI_ISTAIR);
        PyModule_AddIntConstant(m, "KI_ISQUARE", KI_ISQUARE);
        PyModule_AddIntConstant(m, "KI_IVALUE", KI_IVALUE);
        PyModule_AddIntConstant(m, "KI_IINDICATOR", KI_IINDICATOR);
        PyModule_AddIntConstant(m, "KI_IHIGH", KI_IHIGH);
        PyModule_AddIntConstant(m, "KI_ILOW", KI_ILOW);
        PyModule_AddIntConstant(m, "KI_IS400", KI_IS400);
        PyModule_AddIntConstant(m, "KI_IDMM", KI_IDMM);
        PyModule_AddIntConstant(m, "KI_IELECTROMETER", KI_IELECTROMETER);
        PyModule_AddIntConstant(m, "PULSE_MODE_SIMPLE", PULSE_MODE_SIMPLE);
        PyModule_AddIntConstant(m, "PULSE_MODE_ADVANCED", PULSE_MODE_ADVANCED);
        PyModule_AddIntConstant(m, "PULSE_OUTPUT_OFF", PULSE_OUTPUT_OFF);
        PyModule_AddIntConstant(m, "PULSE_OUTPUT_ON", PULSE_OUTPUT_ON);
        PyModule_AddIntConstant(m, "PULSE_MODE_BURST", PULSE_MODE_BURST);
        PyModule_AddIntConstant(m, "PULSE_MODE_CONTINUOUS", PULSE_MODE_CONTINUOUS);
        PyModule_AddIntConstant(m, "PULSE_OUTPUT_NORMAL", PULSE_OUTPUT_NORMAL);
        PyModule_AddIntConstant(m, "PULSE_OUTPUT_COMPLEMENT", PULSE_OUTPUT_COMPLEMENT);
        PyModule_AddIntConstant(m, "PULSE_MODE_PULSE", PULSE_MODE_PULSE);
        PyModule_AddIntConstant(m, "PULSE_MODE_SARB", PULSE_MODE_SARB);
        PyModule_AddIntConstant(m, "PULSE_MODE_ARB", PULSE_MODE_ARB);
        PyModule_AddIntConstant(m, "PULSE_TRIG_SRC_SW", PULSE_TRIG_SRC_SW);
        PyModule_AddIntConstant(m, "PULSE_TRIG_SRC_EXT_INITIAL_RISING", PULSE_TRIG_SRC_EXT_INITIAL_RISING);
        PyModule_AddIntConstant(m, "PULSE_TRIG_SRC_EXT_INITIAL_FALLING", PULSE_TRIG_SRC_EXT_INITIAL_FALLING);
        PyModule_AddIntConstant(m, "PULSE_TRIG_SRC_EXT_PER_PULSE_RISING", PULSE_TRIG_SRC_EXT_PER_PULSE_RISING);
        PyModule_AddIntConstant(m, "PULSE_TRIG_SRC_EXT_PER_PULSE_FALLING", PULSE_TRIG_SRC_EXT_PER_PULSE_FALLING);
        PyModule_AddIntConstant(m, "PULSE_TRIG_SRC_TLINK_RISING", PULSE_TRIG_SRC_TLINK_RISING);
        PyModule_AddIntConstant(m, "PULSE_TRIG_SRC_TLINK_FALLING", PULSE_TRIG_SRC_TLINK_FALLING);
        PyModule_AddIntConstant(m, "PULSE_CAL_5V_50OHM", PULSE_CAL_5V_50OHM);
        PyModule_AddIntConstant(m, "PULSE_CAL_20V_50OHM", PULSE_CAL_20V_50OHM);
        PyModule_AddIntConstant(m, "PMU_TEST_STATUS_IDLE", PMU_TEST_STATUS_IDLE);
        PyModule_AddIntConstant(m, "PMU_TEST_STATUS_RUNNING", PMU_TEST_STATUS_RUNNING);
        PyModule_AddIntConstant(m, "PULSE_NONE_SP", PULSE_NONE_SP);
        PyModule_AddIntConstant(m, "PULSE_BASE_SP", PULSE_BASE_SP);
        PyModule_AddIntConstant(m, "PULSE_AMPLITUDE_SP", PULSE_AMPLITUDE_SP);
        PyModule_AddIntConstant(m, "PULSE_DC_SP", PULSE_DC_SP);
        PyModule_AddIntConstant(m, "PULSE_PERIOD_SP", PULSE_PERIOD_SP);
        PyModule_AddIntConstant(m, "PULSE_WIDTH_SP", PULSE_WIDTH_SP);
        PyModule_AddIntConstant(m, "PULSE_RISE_SP", PULSE_RISE_SP);
        PyModule_AddIntConstant(m, "PULSE_FALL_SP", PULSE_FALL_SP);
        PyModule_AddIntConstant(m, "PULSE_DUAL_BASE_SP", PULSE_DUAL_BASE_SP);
        PyModule_AddIntConstant(m, "PULSE_DUAL_AMPLITUDE_SP", PULSE_DUAL_AMPLITUDE_SP);
        PyModule_AddIntConstant(m, "PULSE_DUAL_DC_SP", PULSE_DUAL_DC_SP);
        PyModule_AddIntConstant(m, "PULSE_LAST_SP", PULSE_LAST_SP);
        PyModule_AddIntConstant(m, "PULSE_MEAS_NONE", PULSE_MEAS_NONE);
        PyModule_AddIntConstant(m, "PULSE_MEAS_SMEAN_PER", PULSE_MEAS_SMEAN_PER);
        PyModule_AddIntConstant(m, "PULSE_MEAS_WFM_PER", PULSE_MEAS_WFM_PER);
        PyModule_AddIntConstant(m, "PULSE_MEAS_SMEAN_BURST", PULSE_MEAS_SMEAN_BURST);
        PyModule_AddIntConstant(m, "PULSE_MEAS_WFM_BURST", PULSE_MEAS_WFM_BURST);
        PyModule_AddIntConstant(m, "PULSE_ACQ_PPERIOD", PULSE_ACQ_PPERIOD);
        PyModule_AddIntConstant(m, "PULSE_ACQ_PBURST", PULSE_ACQ_PBURST);
        PyModule_AddIntConstant(m, "PULSE_MEAS_AUTO", PULSE_MEAS_AUTO);
        PyModule_AddIntConstant(m, "PULSE_MEAS_LTD_AUTO", PULSE_MEAS_LTD_AUTO);
        PyModule_AddIntConstant(m, "PULSE_MEAS_FIXED", PULSE_MEAS_FIXED);
        PyModule_AddIntConstant(m, "PULSE_SRC_IRANGE_40V", PULSE_SRC_IRANGE_40V);
        PyModule_AddIntConstant(m, "PULSE_SRC_IRANGE_10V", PULSE_SRC_IRANGE_10V);
        PyModule_AddIntConstant(m, "PULSE_MEAS_IRANGE_800mA", PULSE_MEAS_IRANGE_800mA);
        PyModule_AddIntConstant(m, "PULSE_MEAS_IRANGE_200mA", PULSE_MEAS_IRANGE_200mA);
        PyModule_AddIntConstant(m, "PULSE_MEAS_IRANGE_10MA", PULSE_MEAS_IRANGE_10MA);
        PyModule_AddIntConstant(m, "PULSE_MEAS_IRANGE_1MA", PULSE_MEAS_IRANGE_1MA);
        PyModule_AddIntConstant(m, "PULSE_MEAS_IRANGE_100UA", PULSE_MEAS_IRANGE_100UA);
        PyModule_AddIntConstant(m, "PULSE_MEAS_IRANGE_10UA", PULSE_MEAS_IRANGE_10UA);
        PyModule_AddIntConstant(m, "PULSE_MEAS_IRANGE_1UA", PULSE_MEAS_IRANGE_1UA);
        PyModule_AddIntConstant(m, "PULSE_MEAS_IRANGE_1NA", PULSE_MEAS_IRANGE_1NA);
        PyModule_AddIntConstant(m, "PMU_OPEN_COMP", PMU_OPEN_COMP);
        PyModule_AddIntConstant(m, "PMU_SHORT_COMP", PMU_SHORT_COMP);
        PyModule_AddIntConstant(m, "PMU_DELAY_COMP", PMU_DELAY_COMP);
        PyModule_AddIntConstant(m, "PMU_COMP_OFF", PMU_COMP_OFF);
        PyModule_AddIntConstant(m, "PMU_PMU_COMP_VAL", PMU_PMU_COMP_VAL);
        PyModule_AddIntConstant(m, "PMU_RPM_COMP_VAL", PMU_RPM_COMP_VAL);
        PyModule_AddIntConstant(m, "PMU_CUSTOM_COMP_VAL", PMU_CUSTOM_COMP_VAL);
        PyModule_AddIntConstant(m, "KI_RPM_PATHWAY", KI_RPM_PATHWAY);
        PyModule_AddIntConstant(m, "KI_RPM_PULSE", KI_RPM_PULSE);
        PyModule_AddIntConstant(m, "KI_RPM_CV_2W", KI_RPM_CV_2W);
        PyModule_AddIntConstant(m, "KI_RPM_CV_4W", KI_RPM_CV_4W);
        PyModule_AddIntConstant(m, "KI_RPM_SMU", KI_RPM_SMU);
        PyModule_AddIntConstant(m, "MINSTATS", MINSTATS);
        PyModule_AddIntConstant(m, "KI_IPVALUE", KI_IPVALUE);
        PyModule_AddIntConstant(m, "KI_VPVALUE", KI_VPVALUE);
        PyModule_AddIntConstant(m, "KI_CPRANGE", KI_CPRANGE);
        PyModule_AddIntConstant(m, "KI_GPRANGE", KI_GPRANGE);
        PyModule_AddIntConstant(m, "KI_IPRANGE", KI_IPRANGE);
        PyModule_AddIntConstant(m, "KI_VPRANGE", KI_VPRANGE);
        PyModule_AddIntConstant(m, "KI_CARANGE", KI_CARANGE);
        PyModule_AddIntConstant(m, "KI_GARANGE", KI_GARANGE);
        PyModule_AddIntConstant(m, "KI_IARANGE", KI_IARANGE);
        PyModule_AddIntConstant(m, "KI_VARANGE", KI_VARANGE);
        PyModule_AddIntConstant(m, "KI_QARANGE", KI_QARANGE);
        PyModule_AddIntConstant(m, "KI_RARANGE", KI_RARANGE);
        PyModule_AddIntConstant(m, "KI_CMRANGE", KI_CMRANGE);
        PyModule_AddIntConstant(m, "KI_GMRANGE", KI_GMRANGE);
        PyModule_AddIntConstant(m, "KI_IMRANGE", KI_IMRANGE);
        PyModule_AddIntConstant(m, "KI_VMRANGE", KI_VMRANGE);
        PyModule_AddIntConstant(m, "KI_UCBPTR", KI_UCBPTR);
        PyModule_AddIntConstant(m, "KI_MODEL", KI_MODEL);
        PyModule_AddIntConstant(m, "KI_COMPLNC", KI_COMPLNC);
        PyModule_AddIntConstant(m, "KI_COMPLIANCE", KI_COMPLIANCE);
        PyModule_AddIntConstant(m, "KI_RANGE_COMPLIANCE", KI_RANGE_COMPLIANCE);
        PyModule_AddIntConstant(m, "KI_IMM_COMPLIANCE", KI_IMM_COMPLIANCE);
        PyModule_AddIntConstant(m, "KI_VPU_PERIOD", KI_VPU_PERIOD);
        PyModule_AddIntConstant(m, "KI_VPU_TRIG_POLARITY", KI_VPU_TRIG_POLARITY);
        PyModule_AddIntConstant(m, "KI_VPU_CARD_STATUS", KI_VPU_CARD_STATUS);
        PyModule_AddIntConstant(m, "KI_VPU_TRIG_SOURCE", KI_VPU_TRIG_SOURCE);
        PyModule_AddIntConstant(m, "KI_VPU_OVER_TEMP", KI_VPU_OVER_TEMP);
        PyModule_AddIntConstant(m, "KI_VPU_CH1_RANGE", KI_VPU_CH1_RANGE);
        PyModule_AddIntConstant(m, "KI_VPU_CH2_RANGE", KI_VPU_CH2_RANGE);
        PyModule_AddIntConstant(m, "KI_VPU_CH1_RISE", KI_VPU_CH1_RISE);
        PyModule_AddIntConstant(m, "KI_VPU_CH2_RISE", KI_VPU_CH2_RISE);
        PyModule_AddIntConstant(m, "KI_VPU_CH1_FALL", KI_VPU_CH1_FALL);
        PyModule_AddIntConstant(m, "KI_VPU_CH2_FALL", KI_VPU_CH2_FALL);
        PyModule_AddIntConstant(m, "KI_VPU_CH1_WIDTH", KI_VPU_CH1_WIDTH);
        PyModule_AddIntConstant(m, "KI_VPU_CH2_WIDTH", KI_VPU_CH2_WIDTH);
        PyModule_AddIntConstant(m, "KI_VPU_CH1_VHIGH", KI_VPU_CH1_VHIGH);
        PyModule_AddIntConstant(m, "KI_VPU_CH2_VHIGH", KI_VPU_CH2_VHIGH);
        PyModule_AddIntConstant(m, "KI_VPU_CH1_VLOW", KI_VPU_CH1_VLOW);
        PyModule_AddIntConstant(m, "KI_VPU_CH2_VLOW", KI_VPU_CH2_VLOW);
        PyModule_AddIntConstant(m, "KI_VPU_CH1_DELAY", KI_VPU_CH1_DELAY);
        PyModule_AddIntConstant(m, "KI_VPU_CH2_DELAY", KI_VPU_CH2_DELAY);
        PyModule_AddIntConstant(m, "KI_VPU_CH1_ILIMIT", KI_VPU_CH1_ILIMIT);
        PyModule_AddIntConstant(m, "KI_VPU_CH2_ILIMIT", KI_VPU_CH2_ILIMIT);
        PyModule_AddIntConstant(m, "KI_VPU_CH1_BURST_COUNT", KI_VPU_CH1_BURST_COUNT);
        PyModule_AddIntConstant(m, "KI_VPU_CH2_BURST_COUNT", KI_VPU_CH2_BURST_COUNT);
        PyModule_AddIntConstant(m, "KI_VPU_CH1_TEST_STATUS", KI_VPU_CH1_TEST_STATUS);
        PyModule_AddIntConstant(m, "KI_VPU_CH2_TEST_STATUS", KI_VPU_CH2_TEST_STATUS);
        PyModule_AddIntConstant(m, "KI_VPU_CH1_DC_OUTPUT", KI_VPU_CH1_DC_OUTPUT);
        PyModule_AddIntConstant(m, "KI_VPU_CH2_DC_OUTPUT", KI_VPU_CH2_DC_OUTPUT);
        PyModule_AddIntConstant(m, "KI_VPU_CH1_LOAD", KI_VPU_CH1_LOAD);
        PyModule_AddIntConstant(m, "KI_VPU_CH2_LOAD", KI_VPU_CH2_LOAD);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_VLIMIT", KI_PXU_CH1_VLIMIT);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_VLIMIT", KI_PXU_CH2_VLIMIT);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_ILIMIT", KI_PXU_CH1_ILIMIT);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_ILIMIT", KI_PXU_CH2_ILIMIT);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_PLIMIT", KI_PXU_CH1_PLIMIT);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_PLIMIT", KI_PXU_CH2_PLIMIT);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_MEASTYPE", KI_PXU_CH1_MEASTYPE);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_MEASTYPE", KI_PXU_CH2_MEASTYPE);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_ACQVHI", KI_PXU_CH1_ACQVHI);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_ACQVHI", KI_PXU_CH2_ACQVHI);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_ACQVLO", KI_PXU_CH1_ACQVLO);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_ACQVLO", KI_PXU_CH2_ACQVLO);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_ACQIHI", KI_PXU_CH1_ACQIHI);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_ACQIHI", KI_PXU_CH2_ACQIHI);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_ACQILO", KI_PXU_CH1_ACQILO);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_ACQILO", KI_PXU_CH2_ACQILO);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_ACQTSTAMP", KI_PXU_CH1_ACQTSTAMP);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_ACQTSTAMP", KI_PXU_CH2_ACQTSTAMP);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_LLC", KI_PXU_CH1_LLC);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_LLC", KI_PXU_CH2_LLC);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_START_PERC", KI_PXU_CH1_START_PERC);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_START_PERC", KI_PXU_CH2_START_PERC);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_STOP_PERC", KI_PXU_CH1_STOP_PERC);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_STOP_PERC", KI_PXU_CH2_STOP_PERC);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_WAVEFORM_PRE", KI_PXU_CH1_WAVEFORM_PRE);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_WAVEFORM_PRE", KI_PXU_CH2_WAVEFORM_PRE);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_WAVEFORM_POST", KI_PXU_CH1_WAVEFORM_POST);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_WAVEFORM_POST", KI_PXU_CH2_WAVEFORM_POST);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_AVG", KI_PXU_CH1_AVG);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_AVG", KI_PXU_CH2_AVG);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_VRANGE", KI_PXU_CH1_VRANGE);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_VRANGE", KI_PXU_CH2_VRANGE);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_IRANGE", KI_PXU_CH1_IRANGE);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_IRANGE", KI_PXU_CH2_IRANGE);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_SAMPLE_RATE", KI_PXU_CH1_SAMPLE_RATE);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_SAMPLE_RATE", KI_PXU_CH2_SAMPLE_RATE);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_RPM_DACA_ILIMIT", KI_PXU_CH1_RPM_DACA_ILIMIT);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_RPM_DACB_ILIMIT", KI_PXU_CH1_RPM_DACB_ILIMIT);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_RPM_DACA_ILIMIT", KI_PXU_CH2_RPM_DACA_ILIMIT);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_RPM_DACB_ILIMIT", KI_PXU_CH2_RPM_DACB_ILIMIT);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_RPM_INIT_ACAL", KI_PXU_CH1_RPM_INIT_ACAL);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_RPM_INIT_ACAL", KI_PXU_CH2_RPM_INIT_ACAL);
        PyModule_AddIntConstant(m, "KI_RPM_CH1_LOCAL_GND_STATE", KI_RPM_CH1_LOCAL_GND_STATE);
        PyModule_AddIntConstant(m, "KI_RPM_CH2_LOCAL_GND_STATE", KI_RPM_CH2_LOCAL_GND_STATE);
        PyModule_AddIntConstant(m, "KI_PXU_LLC_MAX_ITERATIONS", KI_PXU_LLC_MAX_ITERATIONS);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_LLC_TOLERANCE", KI_PXU_CH1_LLC_TOLERANCE);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_LLC_TOLERANCE", KI_PXU_CH2_LLC_TOLERANCE);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_STANDBY", KI_PXU_CH1_STANDBY);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_STANDBY", KI_PXU_CH2_STANDBY);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_LLC_OFFSET", KI_PXU_CH1_LLC_OFFSET);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_LLC_OFFSET", KI_PXU_CH2_LLC_OFFSET);
        PyModule_AddIntConstant(m, "KI_PXU_CH1_HAS_RPM", KI_PXU_CH1_HAS_RPM);
        PyModule_AddIntConstant(m, "KI_PXU_CH2_HAS_RPM", KI_PXU_CH2_HAS_RPM);
        PyModule_AddIntConstant(m, "KI_PMU_CH1_RPM_MODE", KI_PMU_CH1_RPM_MODE);
        PyModule_AddIntConstant(m, "KI_PMU_CH2_RPM_MODE", KI_PMU_CH2_RPM_MODE);
        PyModule_AddIntConstant(m, "KI_PMU_CH1_RPM_RANGE", KI_PMU_CH1_RPM_RANGE);
        PyModule_AddIntConstant(m, "KI_PMU_CH2_RPM_RANGE", KI_PMU_CH2_RPM_RANGE);
        PyModule_AddIntConstant(m, "KI_PMU_CH1_RPM_TEMPERATURE", KI_PMU_CH1_RPM_TEMPERATURE);
        PyModule_AddIntConstant(m, "KI_PMU_CH2_RPM_TEMPERATURE", KI_PMU_CH2_RPM_TEMPERATURE);
        PyModule_AddIntConstant(m, "KI_RPM_CH1_SUPPORT_ILIMIT", KI_RPM_CH1_SUPPORT_ILIMIT);
        PyModule_AddIntConstant(m, "KI_RPM_CH2_SUPPORT_ILIMIT", KI_RPM_CH2_SUPPORT_ILIMIT);
        PyModule_AddIntConstant(m, "KI_CVU_MEASURE_MODEL", KI_CVU_MEASURE_MODEL);
        PyModule_AddIntConstant(m, "KI_CVU_MEASURE_SPEED", KI_CVU_MEASURE_SPEED);
        PyModule_AddIntConstant(m, "KI_CVU_DELAY_FACTOR", KI_CVU_DELAY_FACTOR);
        PyModule_AddIntConstant(m, "KI_CVU_FILTER_FACTOR", KI_CVU_FILTER_FACTOR);
        PyModule_AddIntConstant(m, "KI_CVU_APERTURE", KI_CVU_APERTURE);
        PyModule_AddIntConstant(m, "KI_CVU_CABLE_CORRECT", KI_CVU_CABLE_CORRECT);
        PyModule_AddIntConstant(m, "KI_CVU_OPEN_COMPENSATE", KI_CVU_OPEN_COMPENSATE);
        PyModule_AddIntConstant(m, "KI_CVU_SHORT_COMPENSATE", KI_CVU_SHORT_COMPENSATE);
        PyModule_AddIntConstant(m, "KI_CVU_LOAD_COMPENSATE", KI_CVU_LOAD_COMPENSATE);
        PyModule_AddIntConstant(m, "KI_CVU_DC_SRC_HI", KI_CVU_DC_SRC_HI);
        PyModule_AddIntConstant(m, "KI_CVU_DC_SRC_LO", KI_CVU_DC_SRC_LO);
        PyModule_AddIntConstant(m, "KI_CVU_AC_SRC_HI", KI_CVU_AC_SRC_HI);
        PyModule_AddIntConstant(m, "KI_CVU_AC_MEAS_LO", KI_CVU_AC_MEAS_LO);
        PyModule_AddIntConstant(m, "KI_CVU_DC_SRC_VAL_HI", KI_CVU_DC_SRC_VAL_HI);
        PyModule_AddIntConstant(m, "KI_CVU_DC_SRC_VAL_LO", KI_CVU_DC_SRC_VAL_LO);
        PyModule_AddIntConstant(m, "KI_CVU_OUTPUT_STATE_HI", KI_CVU_OUTPUT_STATE_HI);
        PyModule_AddIntConstant(m, "KI_CVU_OUTPUT_STATE_LO", KI_CVU_OUTPUT_STATE_LO);
        PyModule_AddIntConstant(m, "KI_CVU_SOFTWARE_COMPENSATE", KI_CVU_SOFTWARE_COMPENSATE);
        PyModule_AddIntConstant(m, "KI_CVU_SET_CONSTANT_FILE", KI_CVU_SET_CONSTANT_FILE);
        PyModule_AddIntConstant(m, "KI_CVU_CABLE_LEN_INDEX", KI_CVU_CABLE_LEN_INDEX);
        PyModule_AddIntConstant(m, "KI_CVU_MEASURE_STATUS", KI_CVU_MEASURE_STATUS);
        PyModule_AddIntConstant(m, "KI_CVU_MEASURE_TSTAMP", KI_CVU_MEASURE_TSTAMP);
        PyModule_AddIntConstant(m, "KI_CVU_FREQUENCY", KI_CVU_FREQUENCY);
        PyModule_AddIntConstant(m, "KI_CVU_ACI_RANGE", KI_CVU_ACI_RANGE);
        PyModule_AddIntConstant(m, "KI_CVU_ACI_PRESENT_RANGE", KI_CVU_ACI_PRESENT_RANGE);
        PyModule_AddIntConstant(m, "KI_CVU_ACV_LEVEL", KI_CVU_ACV_LEVEL);
        PyModule_AddIntConstant(m, "KI_CVU_DCV_LEVEL", KI_CVU_DCV_LEVEL);
        PyModule_AddIntConstant(m, "KI_CVU_DCV_OFFSET", KI_CVU_DCV_OFFSET);
        PyModule_AddIntConstant(m, "KI_CVU_SPEED_FAST", KI_CVU_SPEED_FAST);
        PyModule_AddIntConstant(m, "KI_CVU_SPEED_NORMAL", KI_CVU_SPEED_NORMAL);
        PyModule_AddIntConstant(m, "KI_CVU_SPEED_QUIET", KI_CVU_SPEED_QUIET);
        PyModule_AddIntConstant(m, "KI_CVU_SPEED_CUSTOM", KI_CVU_SPEED_CUSTOM);
        PyModule_AddIntConstant(m, "KI_CVU_TYPE_ZTH", KI_CVU_TYPE_ZTH);
        PyModule_AddIntConstant(m, "KI_CVU_TYPE_RJX", KI_CVU_TYPE_RJX);
        PyModule_AddIntConstant(m, "KI_CVU_TYPE_CPGP", KI_CVU_TYPE_CPGP);
        PyModule_AddIntConstant(m, "KI_CVU_TYPE_CSRS", KI_CVU_TYPE_CSRS);
        PyModule_AddIntConstant(m, "KI_CVU_TYPE_CPD", KI_CVU_TYPE_CPD);
        PyModule_AddIntConstant(m, "KI_CVU_TYPE_CSD", KI_CVU_TYPE_CSD);
        PyModule_AddIntConstant(m, "KI_CVU_TYPE_RAW", KI_CVU_TYPE_RAW);
        PyModule_AddIntConstant(m, "CVU_STATUS_MEAS_TIMEOUT", CVU_STATUS_MEAS_TIMEOUT);
        PyModule_AddIntConstant(m, "CVU_STATUS_CVHI1_UNLOCK", CVU_STATUS_CVHI1_UNLOCK);
        PyModule_AddIntConstant(m, "CVU_STATUS_CVHI1_VOFLO", CVU_STATUS_CVHI1_VOFLO);
        PyModule_AddIntConstant(m, "CVU_STATUS_CVHI1_IOFLO", CVU_STATUS_CVHI1_IOFLO);
        PyModule_AddIntConstant(m, "CVU_STATUS_CVLO1_UNLOCK", CVU_STATUS_CVLO1_UNLOCK);
        PyModule_AddIntConstant(m, "CVU_STATUS_CVLO1_VOFLO", CVU_STATUS_CVLO1_VOFLO);
        PyModule_AddIntConstant(m, "CVU_STATUS_CVLO1_IOFLO", CVU_STATUS_CVLO1_IOFLO);
        PyModule_AddIntConstant(m, "MAXSTATS", MAXSTATS);
        PyModule_AddIntConstant(m, "NUMSTATS", NUMSTATS);
        PyModule_AddIntConstant(m, "SMU_TEST_NORMAL", SMU_TEST_NORMAL);
        PyModule_AddIntConstant(m, "SMU_TEST_LIST_SWEEP_ABORTED", SMU_TEST_LIST_SWEEP_ABORTED);
        PyModule_AddIntConstant(m, "KI_SERIALNO", KI_SERIALNO);
        PyModule_AddIntConstant(m, "KI_SW_VERSION", KI_SW_VERSION);
        PyModule_AddIntConstant(m, "KI_HW_VERSION", KI_HW_VERSION);
        PyModule_AddIntConstant(m, "KI_FW_VERSION", KI_FW_VERSION);
        PyModule_AddIntConstant(m, "KI_INSNAME", KI_INSNAME);
        PyModule_AddIntConstant(m, "KI_MODELCODE", KI_MODELCODE);
        PyModule_AddIntConstant(m, "KI_CALDATE", KI_CALDATE);
        PyModule_AddIntConstant(m, "KI_CALDUEDATE", KI_CALDUEDATE);
        PyModule_AddIntConstant(m, "KI_PLATFORM_VERSION", KI_PLATFORM_VERSION);
        PyModule_AddIntConstant(m, "KI_KTEI_VERSION", KI_KTEI_VERSION);
        PyModule_AddIntConstant(m, "KI_CLARIUS_VERSION", KI_CLARIUS_VERSION);
        PyModule_AddIntConstant(m, "KI_CVIV_CH1", KI_CVIV_CH1);
        PyModule_AddIntConstant(m, "KI_CVIV_CH2", KI_CVIV_CH2);
        PyModule_AddIntConstant(m, "KI_CVIV_CH3", KI_CVIV_CH3);
        PyModule_AddIntConstant(m, "KI_CVIV_CH4", KI_CVIV_CH4);
        PyModule_AddIntConstant(m, "KI_CVIV_ALL_CH", KI_CVIV_ALL_CH);
        PyModule_AddIntConstant(m, "KI_CVIV_MAX_CHANNELS", KI_CVIV_MAX_CHANNELS);
        PyModule_AddIntConstant(m, "KI_CVIV_OPEN", KI_CVIV_OPEN);
        PyModule_AddIntConstant(m, "KI_CVIV_SMU", KI_CVIV_SMU);
        PyModule_AddIntConstant(m, "KI_CVIV_CVH", KI_CVIV_CVH);
        PyModule_AddIntConstant(m, "KI_CVIV_CVL", KI_CVIV_CVL);
        PyModule_AddIntConstant(m, "KI_CVIV_CV_GRD", KI_CVIV_CV_GRD);
        PyModule_AddIntConstant(m, "KI_CVIV_DC_COUPLED_AC_GND", KI_CVIV_DC_COUPLED_AC_GND);
        PyModule_AddIntConstant(m, "KI_CVIV_BT_LOI", KI_CVIV_BT_LOI);
        PyModule_AddIntConstant(m, "KI_CVIV_BT_LOI_CVH", KI_CVIV_BT_LOI_CVH);
        PyModule_AddIntConstant(m, "KI_CVIV_BT_LOI_CVL", KI_CVIV_BT_LOI_CVL);
        PyModule_AddIntConstant(m, "KI_CVIV_BT_HII", KI_CVIV_BT_HII);
        PyModule_AddIntConstant(m, "KI_CVIV_BT_HII_CVH", KI_CVIV_BT_HII_CVH);
        PyModule_AddIntConstant(m, "KI_CVIV_BT_HII_CVL", KI_CVIV_BT_HII_CVL);
        PyModule_AddIntConstant(m, "KI_CVIV_BT_AC_GND", KI_CVIV_BT_AC_GND);
        PyModule_AddIntConstant(m, "KI_CVIV_CVU_4WIRE", KI_CVIV_CVU_4WIRE);
        PyModule_AddIntConstant(m, "KI_CVIV_CVU_2WIRE", KI_CVIV_CVU_2WIRE);
        PyModule_AddIntConstant(m, "KI_CVIV_TERMINAL_NAME", KI_CVIV_TERMINAL_NAME);
        PyModule_AddIntConstant(m, "KI_CVIV_TEST_NAME", KI_CVIV_TEST_NAME);
        PyModule_AddIntConstant(m, "KI_CVIV_DISPLAY_OFF", KI_CVIV_DISPLAY_OFF);
        PyModule_AddIntConstant(m, "KI_CVIV_DISPLAY_ON", KI_CVIV_DISPLAY_ON);

        PyModule_AddDoubleConstant(m, "KI_CVU_CABLE_LEN_0m", KI_CVU_CABLE_LEN_0m);
        PyModule_AddDoubleConstant(m, "KI_CVU_CABLE_LEN_1p5m", KI_CVU_CABLE_LEN_1p5m);
        PyModule_AddDoubleConstant(m, "KI_CVU_CABLE_LEN_3m", KI_CVU_CABLE_LEN_3m);
        PyModule_AddDoubleConstant(m, "KI_CVU_CABLE_LEN_CUSTOM", KI_CVU_CABLE_LEN_CUSTOM);
        PyModule_AddDoubleConstant(m, "KI_CVU_CABLE_LEN_CVIV_1p5m_2W", KI_CVU_CABLE_LEN_CVIV_1p5m_2W);
        PyModule_AddDoubleConstant(m, "KI_CVU_CABLE_LEN_CVIV_1p5m_4W_0p75", KI_CVU_CABLE_LEN_CVIV_1p5m_4W_0p75);
        PyModule_AddDoubleConstant(m, "KI_CVU_CABLE_LEN_CVIV_1p5m_4W_0p61Blue", KI_CVU_CABLE_LEN_CVIV_1p5m_4W_0p61Blue);
        PyModule_AddDoubleConstant(m, "KI_CVU_CABLE_LEN_MAX_INDEX", KI_CVU_CABLE_LEN_MAX_INDEX);

        PyModule_AddDoubleConstant(m, "KI_OFF", KI_OFF);
        PyModule_AddDoubleConstant(m, "KI_ON", KI_ON);
        PyModule_AddDoubleConstant(m, "KI_DCON", KI_DCON);
        PyModule_AddDoubleConstant(m, "KI_ACON", KI_ACON);
        PyModule_AddDoubleConstant(m, "KI_ATTEN1X", KI_ATTEN1X);
        PyModule_AddDoubleConstant(m, "KI_ATTEN10X", KI_ATTEN10X);
        PyModule_AddDoubleConstant(m, "KI_FLTON", KI_FLTON);
        PyModule_AddDoubleConstant(m, "KI_FLTOFF", KI_FLTOFF);
        PyModule_AddDoubleConstant(m, "KI_PSLOPE", KI_PSLOPE);
        PyModule_AddDoubleConstant(m, "KI_NSLOPE", KI_NSLOPE);
        PyModule_AddDoubleConstant(m, "KI_AMPS", KI_AMPS);
        PyModule_AddDoubleConstant(m, "KI_COUL", KI_COUL);
        PyModule_AddDoubleConstant(m, "KI_FREQA", KI_FREQA);
        PyModule_AddDoubleConstant(m, "KI_FREQB", KI_FREQB);
        PyModule_AddDoubleConstant(m, "KI_FREQC", KI_FREQC);
        PyModule_AddDoubleConstant(m, "KI_PERIODA", KI_PERIODA);
        PyModule_AddDoubleConstant(m, "KI_AVGPERIODA", KI_AVGPERIODA);
        PyModule_AddDoubleConstant(m, "KI_TIMEATOB", KI_TIMEATOB);
        PyModule_AddDoubleConstant(m, "KI_PULSEA", KI_PULSEA);
        PyModule_AddDoubleConstant(m, "KI_TOTABYB", KI_TOTABYB);
        PyModule_AddDoubleConstant(m, "KI_TOTCUM", KI_TOTCUM);
        PyModule_AddDoubleConstant(m, "KI_ABSOLUTE", KI_ABSOLUTE);
        PyModule_AddDoubleConstant(m, "KI_NORMAL", KI_NORMAL);
        PyModule_AddDoubleConstant(m, "KI_INTEGRATE", KI_INTEGRATE);
        PyModule_AddDoubleConstant(m, "KI_AVERAGE", KI_AVERAGE);
        PyModule_AddDoubleConstant(m, "KI_MEASX", KI_MEASX);
        PyModule_AddDoubleConstant(m, "KI_DC", KI_DC);
        PyModule_AddDoubleConstant(m, "KI_SINGLE_STAIR", KI_SINGLE_STAIR);
        PyModule_AddDoubleConstant(m, "KI_DOUBLE_STAIR", KI_DOUBLE_STAIR);
        PyModule_AddDoubleConstant(m, "KI_PULSE", KI_PULSE);
        PyModule_AddDoubleConstant(m, "KI_EXTERNAL", KI_EXTERNAL);
        PyModule_AddDoubleConstant(m, "KI_STAIR", KI_STAIR);
        PyModule_AddDoubleConstant(m, "KI_SQUARE", KI_SQUARE);
        PyModule_AddDoubleConstant(m, "KI_VALUE", KI_VALUE);
        PyModule_AddDoubleConstant(m, "KI_INDICATOR", KI_INDICATOR);
        PyModule_AddDoubleConstant(m, "KI_HIGH", KI_HIGH);
        PyModule_AddDoubleConstant(m, "KI_LOW", KI_LOW);
        PyModule_AddDoubleConstant(m, "KI_S400", KI_S400);
        PyModule_AddDoubleConstant(m, "KI_DMM", KI_DMM);
        PyModule_AddDoubleConstant(m, "KI_ELECTROMETER", KI_ELECTROMETER);
    }

}

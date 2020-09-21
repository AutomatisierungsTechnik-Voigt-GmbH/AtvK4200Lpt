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

namespace k4200
{

    /// <summary>
    /// K4200 library function parameters.
    /// </summary>
    enum K4200Parameters
    {
        MINMODS = 10001,
        KI_TRIGMODE = 10001,
        KI_AVGNUMBER = 10002,
        KI_AVGTIME = 10003,
        KI_REVIMEAS = 10004,
        KI_MEASURE = 10005,
        KI_IRANGE = 10006,
        KI_QRANGE = 10007,
        KI_ZEROCHECK = 10008,
        KI_ZEROCORRECT = 10009,
        KI_SUPPRESS = 10010,
        KI_VFORCE = 10011,
        KI_SETTRIGA = 10012,
        KI_SETTRIGB = 10013,
        KI_CHANNELA = 10014,
        KI_CHANNELB = 10015,
        KI_SETGATE = 10016,
        KI_POINTSWP = 10017,
        KI_SMARTCLEAR = 10018,
        KI_PSCLEAR = 10019,
        KI_EXTINPUT = 10020,
        KI_SYNC = 10021,
        KI_FREQUENCY = 10023,
        KI_READINGRATE = 10024,
        KI_WAVEFORM = 10025,
        KI_STEPSIZE = 10026,
        KI_TIMEDELAY = 10027,
        KI_INTGPLC = 10028,
        KI_AVGMODE = 10029,
        KI_CC_AUTO = 10030,
        KI_CC_SRC_DLY = 10031,
        KI_CC_COMP_DLY = 10032,
        KI_CC_MEAS_DLY = 10033,
        KI_RANGE_SETTLE = 10034,
        KI_RANGE_DELAY = 10035,
        KI_LIM_INDCTR = 10036,
        KI_MX_DEFMODE = 10037,
        KI_HICURRENT = 10038,
        KI_IMTR = 10039,
        KI_VMTR = 10040,
        KI_LIM_MODE = 10041,
        KI_OUTP_RELAY_STATE = 10042,
        KI_SHIELD_RELAY_STATE = 10043,
        KI_OVP_LEVEL = 10044,
        KI_AVM_LEVEL = 10044,
        KI_TRIG_SRC_TLINK = 10045,
        KI_INIT_IMM = 10046,
        KI_I_READING = 10047,
        KI_V_READING = 10048,
        KI_RDG_STATUS = 10049,
        KI_PREAMP_PRESENT = 10046,
        KI_OUTPUT_STANDBY = 10051,
        KI_TRIG_SRC_IMM = 10052,
        KI_SRC_VOLT_MODE = 10053,
        KI_DELAY_FACTOR = 10054,
        KI_SENSELO = 10055,
        MAXMODS = KI_DELAY_FACTOR,
        NUMMODS = (MAXMODS - MINMODS + 1),
        KI_OUTP_HIZ = 0,
        KI_OUTP_NORM = 1,
        KI_OUTP_ZERO = 2,
        KI_REMOTE = 1,
        KI_LOCAL = 2,
        KI_AUTO = 3,
        NUMMODVAL = 40,
        KI_IOFF = 1,
        KI_ION = 2,
        KI_IDCON = 3,
        KI_IACON = 4,
        KI_IATTEN1X = 5,
        KI_IATTEN10X = 6,
        KI_IFLTON = 7,
        KI_IFLTOFF = 8,
        KI_IPSLOPE = 9,
        KI_INSLOPE = 10,
        KI_IAMPS = 11,
        KI_ICOUL = 12,
        KI_IFREQA = 13,
        KI_IFREQB = 14,
        KI_IFREQC = 15,
        KI_IPERIODA = 16,
        KI_IAVGPERIODA = 17,
        KI_ITIMEATOB = 18,
        KI_IPULSEA = 19,
        KI_ITOTABYB = 20,
        KI_ITOTCUM = 21,
        KI_IABSOLUTE = 22,
        KI_INORMAL = 23,
        KI_IINTEGRATE = 24,
        KI_IAVERAGE = 25,
        KI_IMEASX = 26,
        KI_IDC = 27,
        KI_ISINGLE_STAIR = 28,
        KI_IDOUBLE_STAIR = 29,
        KI_IPULSE = 30,
        KI_IEXTERNAL = 31,
        KI_ISTAIR = 32,
        KI_ISQUARE = 33,
        KI_IVALUE = 34,
        KI_IINDICATOR = 35,
        KI_IHIGH = 36,
        KI_ILOW = 37,
        KI_IS400 = 38,
        KI_IDMM = 39,
        KI_IELECTROMETER = 40,
        PULSE_MODE_SIMPLE = 0,
        PULSE_MODE_ADVANCED = 1,
        PULSE_OUTPUT_OFF = 0,
        PULSE_OUTPUT_ON = 1,
        PULSE_MODE_BURST = 0,
        PULSE_MODE_CONTINUOUS = 1,
        PULSE_OUTPUT_NORMAL = 0,
        PULSE_OUTPUT_COMPLEMENT = 1,
        PULSE_MODE_PULSE = 0,
        PULSE_MODE_SARB = 1,
        PULSE_MODE_ARB = 2,
        PULSE_TRIG_SRC_SW = 0,
        PULSE_TRIG_SRC_EXT_INITIAL_RISING = 1,
        PULSE_TRIG_SRC_EXT_INITIAL_FALLING = 2,
        PULSE_TRIG_SRC_EXT_PER_PULSE_RISING = 3,
        PULSE_TRIG_SRC_EXT_PER_PULSE_FALLING = 4,
        PULSE_TRIG_SRC_TLINK_RISING = 5,
        PULSE_TRIG_SRC_TLINK_FALLING = 6,
        PULSE_CAL_5V_50OHM = 0,
        PULSE_CAL_20V_50OHM = 1,
        PMU_TEST_STATUS_IDLE = 0,
        PMU_TEST_STATUS_RUNNING = 1,
        PULSE_NONE_SP = 0,
        PULSE_BASE_SP = 1,
        PULSE_AMPLITUDE_SP = 2,
        PULSE_DC_SP = 3,
        PULSE_PERIOD_SP = 4,
        PULSE_WIDTH_SP = 5,
        PULSE_RISE_SP = 6,
        PULSE_FALL_SP = 7,
        PULSE_DUAL_BASE_SP = 8,
        PULSE_DUAL_AMPLITUDE_SP = 9,
        PULSE_DUAL_DC_SP = 10,
        PULSE_LAST_SP = PULSE_DUAL_DC_SP,
        PULSE_MEAS_NONE = 0,
        PULSE_MEAS_SMEAN_PER = 1,
        PULSE_MEAS_WFM_PER = 2,
        PULSE_MEAS_SMEAN_BURST = 3,
        PULSE_MEAS_WFM_BURST = 4,
        PULSE_ACQ_PPERIOD = 0,
        PULSE_ACQ_PBURST = 1,
        PULSE_MEAS_AUTO = 0,
        PULSE_MEAS_LTD_AUTO = 1,
        PULSE_MEAS_FIXED = 2,
        PULSE_SRC_IRANGE_40V = 1,
        PULSE_SRC_IRANGE_10V = 0,
        PULSE_MEAS_IRANGE_800mA = 8,
        PULSE_MEAS_IRANGE_200mA = 7,
        PULSE_MEAS_IRANGE_10MA = 6,
        PULSE_MEAS_IRANGE_1MA = 5,
        PULSE_MEAS_IRANGE_100UA = 4,
        PULSE_MEAS_IRANGE_10UA = 3,
        PULSE_MEAS_IRANGE_1UA = 2,
        PULSE_MEAS_IRANGE_1NA = 0,
        PMU_OPEN_COMP = 0,
        PMU_SHORT_COMP = 1,
        PMU_DELAY_COMP = 2,
        PMU_COMP_OFF = 0,
        PMU_PMU_COMP_VAL = 1,
        PMU_RPM_COMP_VAL = 2,
        PMU_CUSTOM_COMP_VAL = 3,
        KI_RPM_PATHWAY = 0,
        KI_RPM_PULSE = 0,
        KI_RPM_CV_2W = 1,
        KI_RPM_CV_4W = 2,
        KI_RPM_SMU = 3,
        MINSTATS = 12001,
        KI_IPVALUE = 12001,
        KI_VPVALUE = 12002,
        KI_CPRANGE = 12003,
        KI_GPRANGE = 12004,
        KI_IPRANGE = 12005,
        KI_VPRANGE = 12006,
        KI_CARANGE = 12007,
        KI_GARANGE = 12008,
        KI_IARANGE = 12009,
        KI_VARANGE = 12010,
        KI_QARANGE = 12011,
        KI_RARANGE = 12012,
        KI_CMRANGE = 12013,
        KI_GMRANGE = 12014,
        KI_IMRANGE = 12015,
        KI_VMRANGE = 12016,
        KI_UCBPTR = 12017,
        KI_MODEL = 12018,
        KI_COMPLNC = 12019,
        KI_COMPLIANCE = 12021,
        KI_RANGE_COMPLIANCE = 12022,
        KI_IMM_COMPLIANCE = 12023,
        KI_VPU_PERIOD = 13001,
        KI_VPU_TRIG_POLARITY = 13002,
        KI_VPU_CARD_STATUS = 13003,
        KI_VPU_TRIG_SOURCE = 13004,
        KI_VPU_OVER_TEMP = 13005,
        KI_VPU_CH1_RANGE = 13100,
        KI_VPU_CH2_RANGE = 13101,
        KI_VPU_CH1_RISE = 13102,
        KI_VPU_CH2_RISE = 13103,
        KI_VPU_CH1_FALL = 13104,
        KI_VPU_CH2_FALL = 13105,
        KI_VPU_CH1_WIDTH = 13106,
        KI_VPU_CH2_WIDTH = 13107,
        KI_VPU_CH1_VHIGH = 13108,
        KI_VPU_CH2_VHIGH = 13109,
        KI_VPU_CH1_VLOW = 13110,
        KI_VPU_CH2_VLOW = 13111,
        KI_VPU_CH1_DELAY = 13112,
        KI_VPU_CH2_DELAY = 13113,
        KI_VPU_CH1_ILIMIT = 13114,
        KI_VPU_CH2_ILIMIT = 13115,
        KI_VPU_CH1_BURST_COUNT = 13116,
        KI_VPU_CH2_BURST_COUNT = 13117,
        KI_VPU_CH1_TEST_STATUS = 13118,
        KI_VPU_CH2_TEST_STATUS = 13119,
        KI_VPU_CH1_DC_OUTPUT = 13120,
        KI_VPU_CH2_DC_OUTPUT = 13121,
        KI_VPU_CH1_LOAD = 13122,
        KI_VPU_CH2_LOAD = 13123,
        KI_PXU_CH1_VLIMIT = 13125,
        KI_PXU_CH2_VLIMIT = 13126,
        KI_PXU_CH1_ILIMIT = 13127,
        KI_PXU_CH2_ILIMIT = 13128,
        KI_PXU_CH1_PLIMIT = 13129,
        KI_PXU_CH2_PLIMIT = 13130,
        KI_PXU_CH1_MEASTYPE = 13131,
        KI_PXU_CH2_MEASTYPE = 13132,
        KI_PXU_CH1_ACQVHI = 13133,
        KI_PXU_CH2_ACQVHI = 13134,
        KI_PXU_CH1_ACQVLO = 13135,
        KI_PXU_CH2_ACQVLO = 13136,
        KI_PXU_CH1_ACQIHI = 13137,
        KI_PXU_CH2_ACQIHI = 13138,
        KI_PXU_CH1_ACQILO = 13139,
        KI_PXU_CH2_ACQILO = 13140,
        KI_PXU_CH1_ACQTSTAMP = 13141,
        KI_PXU_CH2_ACQTSTAMP = 13142,
        KI_PXU_CH1_LLC = 13143,
        KI_PXU_CH2_LLC = 13144,
        KI_PXU_CH1_START_PERC = 13145,
        KI_PXU_CH2_START_PERC = 13146,
        KI_PXU_CH1_STOP_PERC = 13147,
        KI_PXU_CH2_STOP_PERC = 13148,
        KI_PXU_CH1_WAVEFORM_PRE = 13149,
        KI_PXU_CH2_WAVEFORM_PRE = 13150,
        KI_PXU_CH1_WAVEFORM_POST = 13151,
        KI_PXU_CH2_WAVEFORM_POST = 13152,
        KI_PXU_CH1_AVG = 13153,
        KI_PXU_CH2_AVG = 13154,
        KI_PXU_CH1_VRANGE = 13155,
        KI_PXU_CH2_VRANGE = 13156,
        KI_PXU_CH1_IRANGE = 13157,
        KI_PXU_CH2_IRANGE = 13158,
        KI_PXU_CH1_SAMPLE_RATE = 13159,
        KI_PXU_CH2_SAMPLE_RATE = 13160,
        KI_PXU_CH1_RPM_DACA_ILIMIT = 13161,
        KI_PXU_CH1_RPM_DACB_ILIMIT = 13162,
        KI_PXU_CH2_RPM_DACA_ILIMIT = 13163,
        KI_PXU_CH2_RPM_DACB_ILIMIT = 13164,
        KI_PXU_CH1_RPM_INIT_ACAL = 13165,
        KI_PXU_CH2_RPM_INIT_ACAL = 13166,
        KI_RPM_CH1_LOCAL_GND_STATE = 13169,
        KI_RPM_CH2_LOCAL_GND_STATE = 13170,
        KI_PXU_LLC_MAX_ITERATIONS = 13171,
        KI_PXU_CH1_LLC_TOLERANCE = 13172,
        KI_PXU_CH2_LLC_TOLERANCE = 13173,
        KI_PXU_CH1_STANDBY = 13174,
        KI_PXU_CH2_STANDBY = 13175,
        KI_PXU_CH1_LLC_OFFSET = 13176,
        KI_PXU_CH2_LLC_OFFSET = 13177,
        KI_PXU_CH1_HAS_RPM = 13178,
        KI_PXU_CH2_HAS_RPM = 13179,
        KI_PMU_CH1_RPM_MODE = 13180,
        KI_PMU_CH2_RPM_MODE = 13181,
        KI_PMU_CH1_RPM_RANGE = 13182,
        KI_PMU_CH2_RPM_RANGE = 13183,
        KI_PMU_CH1_RPM_TEMPERATURE = 13184,
        KI_PMU_CH2_RPM_TEMPERATURE = 13185,
        KI_RPM_CH1_SUPPORT_ILIMIT = 13186,
        KI_RPM_CH2_SUPPORT_ILIMIT = 13187,
        KI_CVU_MEASURE_MODEL = 14000,
        KI_CVU_MEASURE_SPEED = 14001,
        KI_CVU_DELAY_FACTOR = 14002,
        KI_CVU_FILTER_FACTOR = 14003,
        KI_CVU_APERTURE = 14004,
        KI_CVU_CABLE_CORRECT = 14005,
        KI_CVU_OPEN_COMPENSATE = 14006,
        KI_CVU_SHORT_COMPENSATE = 14007,
        KI_CVU_LOAD_COMPENSATE = 14008,
        KI_CVU_DC_SRC_HI = 14009,
        KI_CVU_DC_SRC_LO = 14010,
        KI_CVU_AC_SRC_HI = 14011,
        KI_CVU_AC_MEAS_LO = 14012,
        KI_CVU_DC_SRC_VAL_HI = 14013,
        KI_CVU_DC_SRC_VAL_LO = 14014,
        KI_CVU_OUTPUT_STATE_HI = 14015,
        KI_CVU_OUTPUT_STATE_LO = 14016,
        KI_CVU_SOFTWARE_COMPENSATE = 14017,
        KI_CVU_SET_CONSTANT_FILE = 14018,
        KI_CVU_CABLE_LEN_INDEX = 14019,
        KI_CVU_MEASURE_STATUS = 15000,
        KI_CVU_MEASURE_TSTAMP = 15001,
        KI_CVU_FREQUENCY = 15002,
        KI_CVU_ACI_RANGE = 15003,
        KI_CVU_ACI_PRESENT_RANGE = 15004,
        KI_CVU_ACV_LEVEL = 15005,
        KI_CVU_DCV_LEVEL = 15006,
        KI_CVU_DCV_OFFSET = 15007,
        KI_CVU_SPEED_FAST = 0,
        KI_CVU_SPEED_NORMAL = 1,
        KI_CVU_SPEED_QUIET = 2,
        KI_CVU_SPEED_CUSTOM = 3,
        KI_CVU_TYPE_ZTH = 0,
        KI_CVU_TYPE_RJX = 1,
        KI_CVU_TYPE_CPGP = 2,
        KI_CVU_TYPE_CSRS = 3,
        KI_CVU_TYPE_CPD = 4,
        KI_CVU_TYPE_CSD = 5,
        KI_CVU_TYPE_RAW = 6,
        CVU_STATUS_MEAS_TIMEOUT = 0x10000000,
        CVU_STATUS_CVHI1_UNLOCK = 0x08000000,
        CVU_STATUS_CVHI1_VOFLO = 0x02000000,
        CVU_STATUS_CVHI1_IOFLO = 0x01000000,
        CVU_STATUS_CVLO1_UNLOCK = 0x00080000,
        CVU_STATUS_CVLO1_VOFLO = 0x00020000,
        CVU_STATUS_CVLO1_IOFLO = 0x00010000,
        MAXSTATS = (KI_UCBPTR),
        NUMSTATS = ((MAXSTATS - MINSTATS) + 1),
        SMU_TEST_NORMAL = 0,
        SMU_TEST_LIST_SWEEP_ABORTED = -1,
        KI_SERIALNO = 16000,
        KI_SW_VERSION = 16001,
        KI_HW_VERSION = 16002,
        KI_FW_VERSION = 16003,
        KI_INSNAME = 16004,
        KI_MODELCODE = 16005,
        KI_CALDATE = 16006,
        KI_CALDUEDATE = 16007,
        KI_PLATFORM_VERSION = 16100,
        KI_KTEI_VERSION = 16101,
        KI_CLARIUS_VERSION = 16101,
        KI_CVIV_CH1 = 1,
        KI_CVIV_CH2 = 2,
        KI_CVIV_CH3 = 3,
        KI_CVIV_CH4 = 4,
        KI_CVIV_ALL_CH = 5,
        KI_CVIV_MAX_CHANNELS = KI_CVIV_ALL_CH,
        KI_CVIV_OPEN = 0,
        KI_CVIV_SMU = 1,
        KI_CVIV_CVH = 2,
        KI_CVIV_CVL = 3,
        KI_CVIV_CV_GRD = 4,
        KI_CVIV_DC_COUPLED_AC_GND = 5,
        KI_CVIV_BT_LOI = 6,
        KI_CVIV_BT_LOI_CVH = 7,
        KI_CVIV_BT_LOI_CVL = 8,
        KI_CVIV_BT_HII = 9,
        KI_CVIV_BT_HII_CVH = 10,
        KI_CVIV_BT_HII_CVL = 11,
        KI_CVIV_BT_AC_GND = 12,
        KI_CVIV_CVU_4WIRE = 0,
        KI_CVIV_CVU_2WIRE = 1,
        KI_CVIV_TERMINAL_NAME = 1,
        KI_CVIV_TEST_NAME = 0,
        KI_CVIV_DISPLAY_OFF = 0,
        KI_CVIV_DISPLAY_ON = 1
    };

    const double KI_CVU_CABLE_LEN_0m = 0.0;
    const double KI_CVU_CABLE_LEN_1p5m = 1.5;
    const double KI_CVU_CABLE_LEN_3m = 3.0;
    const double KI_CVU_CABLE_LEN_CUSTOM = 4.0;
    const double KI_CVU_CABLE_LEN_CVIV_1p5m_2W = 5.0;
    const double KI_CVU_CABLE_LEN_CVIV_1p5m_4W_0p75 = 6.0;
    const double KI_CVU_CABLE_LEN_CVIV_1p5m_4W_0p61Blue = 7.0;
    const double KI_CVU_CABLE_LEN_MAX_INDEX = 7.0;

    const double KI_OFF = 1.0;
    const double KI_ON = 2.0;
    const double KI_DCON = 3.0;
    const double KI_ACON = 4.0;
    const double KI_ATTEN1X = 5.0;
    const double KI_ATTEN10X = 6.0;
    const double KI_FLTON = 7.0;
    const double KI_FLTOFF = 8.0;
    const double KI_PSLOPE = 9.0;
    const double KI_NSLOPE = 10.0;
    const double KI_AMPS = 11.0;
    const double KI_COUL = 12.0;
    const double KI_FREQA = 13.0;
    const double KI_FREQB = 14.0;
    const double KI_FREQC = 15.0;
    const double KI_PERIODA = 16.0;
    const double KI_AVGPERIODA = 17.0;
    const double KI_TIMEATOB = 18.0;
    const double KI_PULSEA = 19.0;
    const double KI_TOTABYB = 20.0;
    const double KI_TOTCUM = 21.0;
    const double KI_ABSOLUTE = 22.0;
    const double KI_NORMAL = 23.0;
    const double KI_INTEGRATE = 24.0;
    const double KI_AVERAGE = 25.0;
    const double KI_MEASX = 26.0;
    const double KI_DC = 27.0;
    const double KI_SINGLE_STAIR = 28.0;
    const double KI_DOUBLE_STAIR = 29.0;
    const double KI_PULSE = 30.0;
    const double KI_EXTERNAL = 31.0;
    const double KI_STAIR = 32.0;
    const double KI_SQUARE = 33.0;
    const double KI_VALUE = 34.0;
    const double KI_INDICATOR = 35.0;
    const double KI_HIGH = 36.0;
    const double KI_LOW = 37.0;
    const double KI_S400 = 38.0;
    const double KI_DMM = 39.0;
    const double KI_ELECTROMETER = 40.0;

} // namespace k4200
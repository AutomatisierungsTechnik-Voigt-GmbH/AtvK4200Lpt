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
#include "K4200LptLibrary.h"
#include "K4200Errors.h"

#include <stdexcept>
#include <string>
#include <vector>

using namespace std;
using namespace k4200;

namespace module
{

    //-------------------------------------------------------------------------------------------------

    /// <summary>
    /// Checks if the function pointer is valid.
    /// </summary>
    /// <param name="funcPtr">The function pointer to be checked.</param>
    /// <returns>True if it is valid.</returns>
    static bool CheckDllFunc(void * funcPtr, const char *funcName)
    {
        if (!IsK4200LptLibraryInitialized())
        {
            PyErr_SetString(GetK4200LptLibraryError(), "LPT library is not initialized!");
            return false;
        }

        if (funcPtr != nullptr)
            return true;

        PyErr_SetString(GetK4200LptLibraryError(), (string("LPT library function pointer of function ") + funcName + " is null!").c_str());
        return false;
    }

    //-------------------------------------------------------------------------------------------------

    /// <summary>
    /// Checks the LPT library function return value for error.
    /// </summary>
    /// <param name="returnValue">The LPT function return value.</param>
    /// <returns>True if an error occurred.</returns>
    static bool CheckFuncReturn(int returnValue, const char *funcName)
    {
        if (returnValue == 0)
        {
            return true;
        }

        string errMsg = string("Keithley 4200 error ") + to_string(returnValue) + " in function " + funcName + ": " + K4200LptErrors::TranslateErrorCode(returnValue);
        PyErr_SetString(GetK4200LptLibraryError(), errMsg.c_str());
        return false;
    }

    //-------------------------------------------------------------------------------------------------

    /// <summary>
    /// Loads and initializes the lpt library to use it in python.
    /// </summary>
    PyObject * K4200LptInitialize(PyObject *self, PyObject *args)
    {
        try
        {
            K4200LptLibraryInitialize();
        }
        catch (exception & exc)
        {
            PyErr_SetString(GetK4200LptLibraryError(), exc.what());
            return nullptr;
        }

        Py_RETURN_NONE;
    }

    //-------------------------------------------------------------------------------------------------

    /// <summary>
    /// Macro for lpt functions without parameters and without return values.
    /// </summary>
    /// <param name="NAME">The name of the lpt library function.</param>
#define FUNC(NAME) \
PyObject * K4200Lpt_##NAME(PyObject *self, PyObject *args) \
{ \
    if (!CheckDllFunc(f_##NAME, #NAME)) \
        return nullptr; \
\
    if (!CheckFuncReturn(f_##NAME(), #NAME)) \
        return nullptr; \
\
    Py_RETURN_NONE; \
}

    FUNC(devclr)
    FUNC(devint)
    FUNC(clrscn)

#undef FUNC0

    //-------------------------------------------------------------------------------------------------

    /// <summary>
    /// Macro for lpt functions with parameters (int) and without return values.
    /// </summary>
    /// <param name="NAME">The name of the lpt library function.</param>
#define FUNC_I(NAME) \
PyObject * K4200Lpt_##NAME(PyObject *self, PyObject *args) \
{ \
    if (!CheckDllFunc(f_##NAME, #NAME)) \
        return nullptr; \
\
    int i; \
\
    if (!PyArg_ParseTuple(args, "i", &i)) \
        return nullptr; \
\
    if (!CheckFuncReturn(f_##NAME(i), #NAME)) \
        return nullptr; \
\
    Py_RETURN_NONE; \
}

    FUNC_I(delay)
    FUNC_I(tstsel)
    FUNC_I(setauto)
    FUNC_I(pulse_init)
    FUNC_I(pulse_halt)
    FUNC_I(cvu_open_comp)
    FUNC_I(cvu_short_comp)
    FUNC_I(cvu_custom_cable_comp)

#undef FUNC_I

    //-------------------------------------------------------------------------------------------------

    PyObject * K4200Lpt_rtfary(PyObject *self, PyObject *args)
    {
        if (!CheckDllFunc(f_rtfary, "rtfary"))
            return nullptr;

        int numPoints;

        if (!PyArg_ParseTuple(args, "i", &numPoints))
            return nullptr;

        vector <double> buffer(numPoints);

        if (!CheckFuncReturn(f_rtfary(&(buffer[0])), "rtfary"))
            return nullptr;

        const auto pyList = PyList_New(numPoints);

        for (int idx = 0; idx < numPoints; idx++)
        {
            PyList_SetItem(pyList, idx, PyFloat_FromDouble(buffer[idx]));
        }

        return pyList;
    }

    //-------------------------------------------------------------------------------------------------

    /// <summary>
    /// Macro for lpt functions with parameters (int, double) and without return values.
    /// </summary>
    /// <param name="NAME">The name of the lpt library function.</param>
#define FUNC_I_D(NAME) \
PyObject * K4200Lpt_##NAME(PyObject *self, PyObject *args) \
{ \
    if (!CheckDllFunc(f_##NAME, #NAME)) \
        return nullptr; \
\
    int i; \
    double d; \
\
    if (!PyArg_ParseTuple(args, "id", &i, &d)) \
        return nullptr; \
\
    if (!CheckFuncReturn(f_##NAME(i, d), #NAME)) \
        return nullptr; \
\
    Py_RETURN_NONE; \
}

    FUNC_I_D(forcei)
    FUNC_I_D(forcev)
    FUNC_I_D(limiti)
    FUNC_I_D(limitv)
    FUNC_I_D(rangei)
    FUNC_I_D(rangev)
    FUNC_I_D(lorangei)
    FUNC_I_D(lorangev)
    FUNC_I_D(setfreq)
    FUNC_I_D(setlevel)
    FUNC_I_D(pulse_period)
    FUNC_I_D(cvu_load_comp)

#undef FUNC_I_D

        //-------------------------------------------------------------------------------------------------

    /// <summary>
    /// Macro for lpt functions with parameters (int) and return values (double).
    /// </summary>
    /// <param name="NAME">The name of the lpt library function.</param>
#define FUNC_I_PD(NAME) \
PyObject * K4200Lpt_##NAME(PyObject *self, PyObject *args) \
{ \
    if (!CheckDllFunc(f_##NAME, #NAME)) \
        return nullptr; \
\
    int i; \
\
    if (!PyArg_ParseTuple(args, "i", &i)) \
        return nullptr; \
\
    double d = 0; \
\
    if (!CheckFuncReturn(f_##NAME(i, &d), #NAME)) \
        return nullptr; \
\
    return PyFloat_FromDouble(d); \
}

    FUNC_I_PD(measi)
    FUNC_I_PD(measv)
    FUNC_I_PD(meast)
    FUNC_I_PD(measf)
    FUNC_I_PD(intgi)
    FUNC_I_PD(intgv)
    FUNC_I_PD(smeasi)
    FUNC_I_PD(smeasv)
    FUNC_I_PD(smeast)
    FUNC_I_PD(sintgi)
    FUNC_I_PD(sintgv)

#undef FUNC_I_PD

    //-------------------------------------------------------------------------------------------------

    PyObject * K4200Lpt_smeasf(PyObject *self, PyObject *args)
    {
        if (!CheckDllFunc(f_smeasf, "smeasf"))
            return nullptr;

        int instId;
        int arraySize;

        if (!PyArg_ParseTuple(args, "ii", &instId, &arraySize))
            return nullptr;

        vector <double> freqArray(arraySize, 0);

        if (!CheckFuncReturn(f_smeasf(instId, &(freqArray[0])), "smeasf"))
            return nullptr;

        const auto pyList = PyList_New(arraySize);

        for (int idx = 0; idx < arraySize; idx++)
        {
            PyList_SetItem(pyList, idx, PyFloat_FromDouble(freqArray[idx]));
        }

        return pyList;
    }

    //-------------------------------------------------------------------------------------------------

    PyObject * K4200Lpt_adelay(PyObject *self, PyObject *args)
    {
        if (!CheckDllFunc(f_adelay, "adelay"))
            return nullptr;

        // get the list of delay times
        PyObject *pList;

        if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &pList))
        {
            PyErr_SetString(GetK4200LptLibraryError(), "adelay: parameter must be a list of delay times.");
            return nullptr;
        }

        auto numPoints = PyList_Size(pList);
        vector <double> delayTimes;

        delayTimes.reserve(numPoints);

        for (int idx = 0; idx < numPoints; idx++)
        {
            auto pItem = PyList_GetItem(pList, idx);

            if (!PyFloat_Check(pItem))
            {
                PyErr_SetString(PyExc_TypeError, "adelay: list items must be floats.");
                return nullptr;
            }

            delayTimes.push_back(PyFloat_AsDouble(pItem));
        }

        // set delay times
        if (!CheckFuncReturn(f_adelay(numPoints, &(delayTimes[0])), "adelay"))
            return nullptr;

        Py_RETURN_NONE;
    }

    //-------------------------------------------------------------------------------------------------

    /// <summary>
    /// Macro for lpt functions with parameters (int, int) and without return values.
    /// </summary>
    /// <param name="NAME">The name of the lpt library function.</param>
#define FUNC_I_I(NAME) \
PyObject * K4200Lpt_##NAME(PyObject *self, PyObject *args) \
{ \
    if (!CheckDllFunc(f_##NAME, #NAME)) \
        return nullptr; \
\
    int i1, i2; \
\
    if (!PyArg_ParseTuple(args, "ii", &i1, &i2)) \
        return nullptr; \
\
    if (!CheckFuncReturn(f_##NAME(i1, i2), #NAME)) \
        return nullptr; \
\
    Py_RETURN_NONE; \
}

    FUNC_I_I(pg2_init)
    FUNC_I_I(pulse_trig_output)
    FUNC_I_I(pulse_trig)
    FUNC_I_I(pulse_trig_polarity)
    FUNC_I_I(pulse_trig_source)
    FUNC_I_I(pulse_float)

#undef FUNC_I_I

    //-------------------------------------------------------------------------------------------------

    PyObject * K4200Lpt_getinstname(PyObject *self, PyObject *args)
    {
        if (!CheckDllFunc(f_getinstname, "getinstname"))
            return nullptr;

        int instId;

        if (!PyArg_ParseTuple(args, "i", &instId))
            return nullptr;

        char instName[128];

        memset(instName, 0, sizeof(instName));

        if (!CheckFuncReturn(f_getinstname(instId, instName), "getinstname"))
            return nullptr;

        return PyUnicode_FromString(instName);
    }

    //-------------------------------------------------------------------------------------------------

    PyObject * K4200Lpt_getinstid(PyObject *self, PyObject *args)
    {
        if (!CheckDllFunc(f_getinstid, "getinstid"))
            return nullptr;

        const char *instName;

        if (!PyArg_ParseTuple(args, "s", &instName))
            return nullptr;

        int instId = 0;

        if (!CheckFuncReturn(f_getinstid(instName, &instId), "getinstid"))
            return nullptr;

        return PyLong_FromLong(instId);
    }

    //-------------------------------------------------------------------------------------------------

    /// <summary>
    /// Macro for lpt functions with parameters (int, int, double) and without return values.
    /// </summary>
    /// <param name="NAME">The name of the lpt library function.</param>
#define FUNC_I_I_D(NAME) \
PyObject * K4200Lpt_##NAME(PyObject *self, PyObject *args) \
{ \
    if (!CheckDllFunc(f_##NAME, #NAME)) \
        return nullptr; \
\
    int i1, i2; \
    double d; \
\
    if (!PyArg_ParseTuple(args, "iid", &i1, &i2, &d)) \
        return nullptr; \
\
    if (!CheckFuncReturn(f_##NAME(i1, i2, d), #NAME)) \
        return nullptr; \
\
    Py_RETURN_NONE; \
}

    FUNC_I_I_D(setmode)
    FUNC_I_I_D(pulse_range)
    FUNC_I_I_D(pulse_rise)
    FUNC_I_I_D(pulse_fall)
    FUNC_I_I_D(pulse_width)
    FUNC_I_I_D(pulse_vhigh)
    FUNC_I_I_D(pulse_vlow)
    FUNC_I_I_D(pulse_delay)
    FUNC_I_I_D(pulse_current_limit)
    FUNC_I_I_D(pulse_load)
    FUNC_I_I_D(pulse_dc_output)

#undef FUNC_I_I_D

        //-------------------------------------------------------------------------------------------------

    /// <summary>
    /// Macro for lpt functions with parameters (int, int, int) and without return values.
    /// </summary>
    /// <param name="NAME">The name of the lpt library function.</param>
#define FUNC_I_I_I(NAME) \
PyObject * K4200Lpt_##NAME(PyObject *self, PyObject *args) \
{ \
    if (!CheckDllFunc(f_##NAME, #NAME)) \
        return nullptr; \
\
    int i1, i2, i3; \
\
    if (!PyArg_ParseTuple(args, "iii", &i1, &i2, &i3)) \
        return nullptr; \
\
    if (!CheckFuncReturn(f_##NAME(i1, i2, i3), #NAME)) \
        return nullptr; \
\
    Py_RETURN_NONE; \
}

    FUNC_I_I_I(pulse_output)
    FUNC_I_I_I(pulse_output_mode)
    FUNC_I_I_I(pulse_burst_count)

#undef FUNC_I_I_I

    //-------------------------------------------------------------------------------------------------

    PyObject * K4200Lpt_getstatus(PyObject *self, PyObject *args)
    {
        if (!CheckDllFunc(f_getstatus, "getstatus"))
            return nullptr;

        int instId, parameter;

        if (!PyArg_ParseTuple(args, "id", &instId, &parameter))
            return nullptr;

        double value = 0;

        if (!CheckFuncReturn(f_getstatus(instId, parameter, &value), "getstatus"))
            return nullptr;

        return PyFloat_FromDouble(value);
    }

    //-------------------------------------------------------------------------------------------------

    PyObject * K4200Lpt_kibcmd(PyObject *self, PyObject *args)
    {
        if (!CheckDllFunc(f_kibcmd, "kibcmd"))
            return nullptr;

        int timeout;
        const char *cmdBuffer;

        if (!PyArg_ParseTuple(args, "is", &timeout, &cmdBuffer))
            return nullptr;

        if (!CheckFuncReturn(f_kibcmd(timeout, strlen(cmdBuffer), cmdBuffer), "kibcmd"))
            return nullptr;

        Py_RETURN_NONE;
    }

    //-------------------------------------------------------------------------------------------------

    PyObject * K4200Lpt_kibspl(PyObject *self, PyObject *args)
    {
        if (!CheckDllFunc(f_kibspl, "kibspl"))
            return nullptr;

        int priAddr, secAddr, timeout;

        if (!PyArg_ParseTuple(args, "iii", &priAddr, &secAddr, &timeout))
            return nullptr;

        int statusByte = 0;

        if (!CheckFuncReturn(f_kibspl(priAddr, secAddr, timeout, &statusByte), "kibspl"))
            return nullptr;

        Py_RETURN_NONE;
    }

    //-------------------------------------------------------------------------------------------------

    PyObject * K4200Lpt_kspsnd(PyObject *self, PyObject *args)
    {
        if (!CheckDllFunc(f_kspsnd, "kspsnd"))
            return nullptr;

        int port;
        double timeout;
        const char *cmd;

        if (!PyArg_ParseTuple(args, "ids", &port, &timeout, &cmd))
            return nullptr;

        if (!CheckFuncReturn(f_kspsnd(port, timeout, strlen(cmd), cmd), "kspsnd"))
            return nullptr;

        Py_RETURN_NONE;
    }

    //-------------------------------------------------------------------------------------------------

    PyObject * K4200Lpt_pulse_ssrc(PyObject *self, PyObject *args)
    {
        if (!CheckDllFunc(f_pulse_ssrc, "pulse_ssrc"))
            return nullptr;

        int instId;
        int channel;
        int state;
        int ctrl;

        if (!PyArg_ParseTuple(args, "iiii", &instId, &channel, &state, &ctrl))
            return nullptr;

        if (!CheckFuncReturn(f_pulse_ssrc(instId, channel, state, ctrl), "pulse_ssrc"))
            return nullptr;

        Py_RETURN_NONE;
    }

    //-------------------------------------------------------------------------------------------------

    PyObject * K4200Lpt_pulse_getcal(PyObject *self, PyObject *args)
    {
        if (!CheckDllFunc(f_pulse_getcal, "pulse_getcal"))
            return nullptr;

        int instId;
        int channel;
        int index;

        if (!PyArg_ParseTuple(args, "iii", &instId, &channel, &index))
            return nullptr;

        double calVal = 0;

        if (!CheckFuncReturn(f_pulse_getcal(instId, channel, index, &calVal), "pulse_getcal"))
            return nullptr;

        return PyFloat_FromDouble(calVal);
    }

    //-------------------------------------------------------------------------------------------------

    PyObject * K4200Lpt_asweepv(PyObject *self, PyObject *args)
    {
        if (!CheckDllFunc(f_asweepv, "asweepv"))
            return nullptr;

        int instId;
        double delayTime;
        PyObject *pList;

        if (!PyArg_ParseTuple(args, "idO!", &instId, &delayTime, &PyList_Type, &pList))
            return nullptr;

        // get the list of delay times
        auto numPoints = PyList_Size(pList);
        vector <double> values;

        values.reserve(numPoints);

        for (int idx = 0; idx < numPoints; idx++)
        {
            auto pItem = PyList_GetItem(pList, idx);

            if (!PyFloat_Check(pItem))
            {
                PyErr_SetString(PyExc_TypeError, "asweepv: list items must be floats.");
                return nullptr;
            }

            values.push_back(PyFloat_AsDouble(pItem));
        }

        if (!CheckFuncReturn(f_asweepv(instId, numPoints, delayTime, &(values[0])), "asweepv"))
            return nullptr;

        Py_RETURN_NONE;
    }

    //-------------------------------------------------------------------------------------------------

    PyObject * K4200Lpt_asweepi(PyObject *self, PyObject *args)
    {
        if (!CheckDllFunc(f_asweepi, "asweepi"))
            return nullptr;

        int instId;
        double delayTime;
        PyObject *pList;

        if (!PyArg_ParseTuple(args, "idO!", &instId, &delayTime, &PyList_Type, &pList))
            return nullptr;

        // get the list of delay times
        auto numPoints = PyList_Size(pList);
        vector <double> values;

        values.reserve(numPoints);

        for (int idx = 0; idx < numPoints; idx++)
        {
            auto pItem = PyList_GetItem(pList, idx);

            if (!PyFloat_Check(pItem))
            {
                PyErr_SetString(PyExc_TypeError, "asweepi: list items must be floats.");
                return nullptr;
            }

            values.push_back(PyFloat_AsDouble(pItem));
        }

        if (!CheckFuncReturn(f_asweepi(instId, numPoints, delayTime, &(values[0])), "asweepi"))
            return nullptr;

        Py_RETURN_NONE;
    }

    //-------------------------------------------------------------------------------------------------

    /// <summary>
    /// Macro for lpt functions with parameters (int, int, int) and with return values (double, double).
    /// </summary>
    /// <param name="NAME">The name of the lpt library function.</param>
#define FUNC_I_I_I_DP_DP(NAME) \
PyObject * K4200Lpt_##NAME(PyObject *self, PyObject *args) \
{ \
    if (!CheckDllFunc(f_##NAME, #NAME)) \
        return nullptr; \
\
    int i1, i2, i3; \
\
    if (!PyArg_ParseTuple(args, "iii", &i1, &i2, &i3)) \
        return nullptr; \
\
    double d1 = 0, d2 = 0; \
\
    if (!CheckFuncReturn(f_##NAME(i1, i2, i3, &d1, &d2), #NAME)) \
        return nullptr; \
\
    return Py_BuildValue("(dd)", d1, d2); \
}

    FUNC_I_I_I_DP_DP(measz)
    FUNC_I_I_I_DP_DP(smeasz)

#undef FUNC_I_I_I_DP_DP

        //-------------------------------------------------------------------------------------------------

    /// <summary>
    /// Macro for lpt functions with parameters (int, double, double, int, double) and without return values.
    /// </summary>
    /// <param name="NAME">The name of the lpt library function.</param>
#define FUNC_I_D_D_I_D(NAME) \
PyObject * K4200Lpt_##NAME(PyObject *self, PyObject *args) \
{ \
    if (!CheckDllFunc(f_##NAME, #NAME)) \
        return nullptr; \
\
    int i1, i2; \
    double d1, d2, d3; \
\
    if (!PyArg_ParseTuple(args, "iddid", &i1, &d1, &d2, &i2, &d3)) \
        return nullptr; \
\
    if (!CheckFuncReturn(f_##NAME(i1, d1, d2, i2, d3), #NAME)) \
        return nullptr; \
\
    Py_RETURN_NONE; \
}

    FUNC_I_D_D_I_D(sweepi)
    FUNC_I_D_D_I_D(sweepv)
    FUNC_I_D_D_I_D(dsweepv)

#undef FUNC_I_D_D_I_D

        //-------------------------------------------------------------------------------------------------

    /// <summary>
    /// Macro for lpt functions with parameters (int, double, double, double) and with return values (int).
    /// </summary>
    /// <param name="NAME">The name of the lpt library function.</param>
#define FUNC_I_D_D_IP_D(NAME) \
PyObject * K4200Lpt_##NAME(PyObject *self, PyObject *args) \
{ \
    if (!CheckDllFunc(f_##NAME, #NAME)) \
        return nullptr; \
\
    int i1; \
    double d1, d2, d3; \
\
    if (!PyArg_ParseTuple(args, "iddd", &i1, &d1, &d2, &d3)) \
        return nullptr; \
\
    int numPoints = 0; \
\
    if (!CheckFuncReturn(f_##NAME(i1, d1, d2, &numPoints, d3), #NAME)) \
        return nullptr; \
\
    return PyLong_FromLong(numPoints); \
}

    FUNC_I_D_D_IP_D(sweepf)
    FUNC_I_D_D_IP_D(dsweepf)

#undef FUNC_I_D_D_IP_D

    //-------------------------------------------------------------------------------------------------

    PyObject * K4200Lpt_kibsnd(PyObject *self, PyObject *args)
    {
        if (!CheckDllFunc(f_kibsnd, "kibsnd"))
            return nullptr;

        int priAddr;
        int secAddr;
        int timeout;
        const char *sendBuff;

        if (!PyArg_ParseTuple(args, "iiis", &priAddr, &secAddr, &timeout, &sendBuff))
            return nullptr;

        if (!CheckFuncReturn(f_kibsnd(priAddr, secAddr, timeout, strlen(sendBuff), sendBuff), "kibsnd"))
            return nullptr;

        Py_RETURN_NONE;
    }

    //-------------------------------------------------------------------------------------------------

    /// <summary>
    /// Macro for lpt functions with parameters (int, double, double, int, double) and with return values (double).
    /// </summary>
    /// <param name="NAME">The name of the lpt library function.</param>
#define FUNC_I_D_D_I_D_DP(NAME) \
PyObject * K4200Lpt_##NAME(PyObject *self, PyObject *args) \
{ \
    if (!CheckDllFunc(f_##NAME, #NAME)) \
        return nullptr; \
\
    int i1, i2; \
    double d1, d2, d3; \
\
    if (!PyArg_ParseTuple(args, "iddid", &i1, &d1, &d2, &i2, &d3)) \
        return nullptr; \
\
    double result = 0; \
\
    if (!CheckFuncReturn(f_##NAME(i1, d1, d2, i2, d3, &result), #NAME)) \
        return nullptr; \
\
    return PyFloat_FromDouble(result); \
}

    FUNC_I_D_D_I_D_DP(bsweepi)
    FUNC_I_D_D_I_D_DP(bsweepv)

#undef FUNC_I_D_D_I_D_DP

    //-------------------------------------------------------------------------------------------------

    PyObject * K4200Lpt_kspcfg(PyObject *self, PyObject *args)
    {
        if (!CheckDllFunc(f_kspcfg, "kspcfg"))
            return nullptr;

        int port;
        int baud;
        int dataBits;
        int parity;
        int stopBits;
        int flowCtl;

        if (!PyArg_ParseTuple(args, "iiiiii", &port, &baud, &dataBits, &parity, &stopBits, &flowCtl))
            return nullptr;

        if (!CheckFuncReturn(f_kspcfg(port, baud, dataBits, parity, stopBits, flowCtl), "kspcfg"))
            return nullptr;

        Py_RETURN_NONE;
    }

    //-------------------------------------------------------------------------------------------------

    PyObject * K4200Lpt_ksprcv(PyObject *self, PyObject *args)
    {
        if (!CheckDllFunc(f_ksprcv, "ksprcv"))
            return nullptr;

        int port;
        char terminator;
        double timeout;
        int rcvSize;

        if (!PyArg_ParseTuple(args, "iCdi", &port, &terminator, &timeout, &rcvSize))
            return nullptr;

        if ((rcvSize < 1) || (rcvSize > 1000000000))
        {
            PyErr_SetString(PyExc_TypeError, "ksprcv: rcvsize is too large or too small.");
            return nullptr;
        }

        int rcvLen = 0;
        vector <char> rcvBuffer(rcvSize + 3, '\0');

        if (!CheckFuncReturn(f_ksprcv(port, terminator, timeout, rcvSize, &rcvLen, &(rcvBuffer[0])), "ksprcv"))
            return nullptr;

        return PyUnicode_FromStringAndSize(&(rcvBuffer[0]), rcvLen);
    }

    //-------------------------------------------------------------------------------------------------

    PyObject * K4200Lpt_kibrcv(PyObject *self, PyObject *args)
    {
        if (!CheckDllFunc(f_kibrcv, "kibrcv"))
            return nullptr;

        int priAddr;
        int secAddr;
        char terminator;
        int timeout;
        int rcvSize;

        if (!PyArg_ParseTuple(args, "iiCii", &priAddr, &secAddr, &terminator, &timeout, &rcvSize))
            return nullptr;

        unsigned int rcvLen = 0;
        vector <char> rcvBuffer(rcvSize + 3, '\0');

        if (!CheckFuncReturn(f_kibrcv(priAddr, secAddr, terminator, timeout, rcvSize, &rcvLen, &(rcvBuffer[0])), "kibrcv"))
            return nullptr;

        return PyUnicode_FromStringAndSize(&(rcvBuffer[0]), rcvLen);
    }

    //-------------------------------------------------------------------------------------------------

    PyObject * K4200LptTest(PyObject *self, PyObject *args)
    {
        double d1, d2;

        if (!PyArg_ParseTuple(args, "dd", &d1, &d2))
            return nullptr;

        return Py_BuildValue("(dd)", d1 * d2, d1 + d2);
    }

    //-------------------------------------------------------------------------------------------------

} // namespace module


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

#include "K4200ModuleInstruments.h"
#include "K4200Instruments.h"

using namespace k4200;

namespace module
{
    //-------------------------------------------------------------------------------------------------
    // prototypes

    /// <summary>
    /// Adds all K4200 lpt library instrument IDs to a python object.
    /// </summary>
    /// <param name="m">The python object where the constants shall be added.</param>
    void K4200AddConstantsInstruments(PyObject *m);

    //-------------------------------------------------------------------------------------------------

    /// <summary>
    /// Python module method table.
    /// </summary>
    static PyMethodDef K4200ModuleInstrumentsMethods[] =
    {
        { nullptr, nullptr, 0, nullptr} // end of methods
    };

    //-------------------------------------------------------------------------------------------------

    /// <summary>
    /// Python module definition.
    /// </summary>
    static struct PyModuleDef K4200ModuleInstruments =
    {
        PyModuleDef_HEAD_INIT,
        "k4200instruments",                           // name of module
        "Keithley 4200 LPT library instrument IDs.",  // module documentation, may be NULL
        -1,                                           // size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
        K4200ModuleInstrumentsMethods
    };

} // namespace module

//-------------------------------------------------------------------------------------------------

extern "C"
{
    /// <summary>
    /// Python module initialization.
    /// </summary>
    /// <returns>The python module.</returns>
    PyMODINIT_FUNC PyInit_k4200instruments()
    {
        const auto m = PyModule_Create(&module::K4200ModuleInstruments);
        if (m == nullptr)
            return nullptr;

        module::K4200AddConstantsInstruments(m);

        return m;
    }
}

//-------------------------------------------------------------------------------------------------

namespace module
{

    /// <summary>
    /// Adds all K4200 lpt library instrument IDs to a python object.
    /// </summary>
    /// <param name="m">The python object where the constants shall be added.</param>
    void K4200AddConstantsInstruments(PyObject *m)
    {
        PyModule_AddIntConstant(m, "KI_EOC", KI_EOC);
        PyModule_AddIntConstant(m, "KI_NOINSTR", KI_NOINSTR);
        PyModule_AddIntConstant(m, "MINNAME", MINNAME);
        PyModule_AddIntConstant(m, "GND", GND);
        PyModule_AddIntConstant(m, "GNDU", GNDU);
        PyModule_AddIntConstant(m, "GNDUF", GNDUF);
        PyModule_AddIntConstant(m, "SMU1L", SMU1L);
        PyModule_AddIntConstant(m, "SMU1OL", SMU1OL);
        PyModule_AddIntConstant(m, "SMU2L", SMU2L);
        PyModule_AddIntConstant(m, "SMU2OL", SMU2OL);
        PyModule_AddIntConstant(m, "SMU3L", SMU3L);
        PyModule_AddIntConstant(m, "SMU3OL", SMU3OL);
        PyModule_AddIntConstant(m, "SMU4L", SMU4L);
        PyModule_AddIntConstant(m, "SMU4OL", SMU4OL);
        PyModule_AddIntConstant(m, "SMU5L", SMU5L);
        PyModule_AddIntConstant(m, "SMU5OL", SMU5OL);
        PyModule_AddIntConstant(m, "SMU6L", SMU6L);
        PyModule_AddIntConstant(m, "SMU6OL", SMU6OL);
        PyModule_AddIntConstant(m, "SMU7L", SMU7L);
        PyModule_AddIntConstant(m, "SMU7OL", SMU7OL);
        PyModule_AddIntConstant(m, "SMU8L", SMU8L);
        PyModule_AddIntConstant(m, "SMU8OL", SMU8OL);
        PyModule_AddIntConstant(m, "SMU9L", SMU9L);
        PyModule_AddIntConstant(m, "SMU9OL", SMU9OL);
        PyModule_AddIntConstant(m, "SMU10L", SMU10L);
        PyModule_AddIntConstant(m, "SMU10OL", SMU10OL);
        PyModule_AddIntConstant(m, "GPT1L", GPT1L);
        PyModule_AddIntConstant(m, "GPT1OL", GPT1OL);
        PyModule_AddIntConstant(m, "GPT2L", GPT2L);
        PyModule_AddIntConstant(m, "GPT2OL", GPT2OL);
        PyModule_AddIntConstant(m, "GPT3L", GPT3L);
        PyModule_AddIntConstant(m, "GPT3OL", GPT3OL);
        PyModule_AddIntConstant(m, "GPT4L", GPT4L);
        PyModule_AddIntConstant(m, "GPT4OL", GPT4OL);
        PyModule_AddIntConstant(m, "GPT5L", GPT5L);
        PyModule_AddIntConstant(m, "GPT5OL", GPT5OL);
        PyModule_AddIntConstant(m, "GPT6L", GPT6L);
        PyModule_AddIntConstant(m, "GPT6OL", GPT6OL);
        PyModule_AddIntConstant(m, "GPT7L", GPT7L);
        PyModule_AddIntConstant(m, "GPT7OL", GPT7OL);
        PyModule_AddIntConstant(m, "GPT8L", GPT8L);
        PyModule_AddIntConstant(m, "GPT8OL", GPT8OL);
        PyModule_AddIntConstant(m, "GNDUS", GNDUS);
        PyModule_AddIntConstant(m, "CHUCK", CHUCK);
        PyModule_AddIntConstant(m, "KI_SYSTEM", KI_SYSTEM);
        PyModule_AddIntConstant(m, "SMU1", SMU1);
        PyModule_AddIntConstant(m, "SMU1F", SMU1F);
        PyModule_AddIntConstant(m, "SMU1H", SMU1H);
        PyModule_AddIntConstant(m, "SMU1OH", SMU1OH);
        PyModule_AddIntConstant(m, "SMU1S", SMU1S);
        PyModule_AddIntConstant(m, "SMU1SH", SMU1SH);
        PyModule_AddIntConstant(m, "SMU2", SMU2);
        PyModule_AddIntConstant(m, "SMU2F", SMU2F);
        PyModule_AddIntConstant(m, "SMU2H", SMU2H);
        PyModule_AddIntConstant(m, "SMU2OH", SMU2OH);
        PyModule_AddIntConstant(m, "SMU2S", SMU2S);
        PyModule_AddIntConstant(m, "SMU2SH", SMU2SH);
        PyModule_AddIntConstant(m, "SMU3", SMU3);
        PyModule_AddIntConstant(m, "SMU3F", SMU3F);
        PyModule_AddIntConstant(m, "SMU3H", SMU3H);
        PyModule_AddIntConstant(m, "SMU3OH", SMU3OH);
        PyModule_AddIntConstant(m, "SMU3S", SMU3S);
        PyModule_AddIntConstant(m, "SMU3SH", SMU3SH);
        PyModule_AddIntConstant(m, "SMU4", SMU4);
        PyModule_AddIntConstant(m, "SMU4F", SMU4F);
        PyModule_AddIntConstant(m, "SMU4H", SMU4H);
        PyModule_AddIntConstant(m, "SMU4OH", SMU4OH);
        PyModule_AddIntConstant(m, "SMU4S", SMU4S);
        PyModule_AddIntConstant(m, "SMU4SH", SMU4SH);
        PyModule_AddIntConstant(m, "SMU5", SMU5);
        PyModule_AddIntConstant(m, "SMU5F", SMU5F);
        PyModule_AddIntConstant(m, "SMU5H", SMU5H);
        PyModule_AddIntConstant(m, "SMU5OH", SMU5OH);
        PyModule_AddIntConstant(m, "SMU5S", SMU5S);
        PyModule_AddIntConstant(m, "SMU5SH", SMU5SH);
        PyModule_AddIntConstant(m, "SMU6", SMU6);
        PyModule_AddIntConstant(m, "SMU6F", SMU6F);
        PyModule_AddIntConstant(m, "SMU6H", SMU6H);
        PyModule_AddIntConstant(m, "SMU6OH", SMU6OH);
        PyModule_AddIntConstant(m, "SMU6S", SMU6S);
        PyModule_AddIntConstant(m, "SMU6SH", SMU6SH);
        PyModule_AddIntConstant(m, "SMU7", SMU7);
        PyModule_AddIntConstant(m, "SMU7F", SMU7F);
        PyModule_AddIntConstant(m, "SMU7H", SMU7H);
        PyModule_AddIntConstant(m, "SMU7OH", SMU7OH);
        PyModule_AddIntConstant(m, "SMU7S", SMU7S);
        PyModule_AddIntConstant(m, "SMU7SH", SMU7SH);
        PyModule_AddIntConstant(m, "SMU8", SMU8);
        PyModule_AddIntConstant(m, "SMU8F", SMU8F);
        PyModule_AddIntConstant(m, "SMU8H", SMU8H);
        PyModule_AddIntConstant(m, "SMU8OH", SMU8OH);
        PyModule_AddIntConstant(m, "SMU8S", SMU8S);
        PyModule_AddIntConstant(m, "SMU8SH", SMU8SH);
        PyModule_AddIntConstant(m, "SMU9", SMU9);
        PyModule_AddIntConstant(m, "SMU9F", SMU9F);
        PyModule_AddIntConstant(m, "SMU9H", SMU9H);
        PyModule_AddIntConstant(m, "SMU9OH", SMU9OH);
        PyModule_AddIntConstant(m, "SMU9S", SMU9S);
        PyModule_AddIntConstant(m, "SMU9SH", SMU9SH);
        PyModule_AddIntConstant(m, "SMU10", SMU10);
        PyModule_AddIntConstant(m, "SMU10F", SMU10F);
        PyModule_AddIntConstant(m, "SMU10H", SMU10H);
        PyModule_AddIntConstant(m, "SMU10OH", SMU10OH);
        PyModule_AddIntConstant(m, "SMU10S", SMU10S);
        PyModule_AddIntConstant(m, "SMU10SH", SMU10SH);
        PyModule_AddIntConstant(m, "GPT1", GPT1);
        PyModule_AddIntConstant(m, "GPT1F", GPT1F);
        PyModule_AddIntConstant(m, "GPT1H", GPT1H);
        PyModule_AddIntConstant(m, "GPT1OH", GPT1OH);
        PyModule_AddIntConstant(m, "GPT1S", GPT1S);
        PyModule_AddIntConstant(m, "GPT1SH", GPT1SH);
        PyModule_AddIntConstant(m, "GPT2", GPT2);
        PyModule_AddIntConstant(m, "GPT2F", GPT2F);
        PyModule_AddIntConstant(m, "GPT2H", GPT2H);
        PyModule_AddIntConstant(m, "GPT2OH", GPT2OH);
        PyModule_AddIntConstant(m, "GPT2S", GPT2S);
        PyModule_AddIntConstant(m, "GPT2SH", GPT2SH);
        PyModule_AddIntConstant(m, "GPT3", GPT3);
        PyModule_AddIntConstant(m, "GPT3F", GPT3F);
        PyModule_AddIntConstant(m, "GPT3H", GPT3H);
        PyModule_AddIntConstant(m, "GPT3OH", GPT3OH);
        PyModule_AddIntConstant(m, "GPT3S", GPT3S);
        PyModule_AddIntConstant(m, "GPT3SH", GPT3SH);
        PyModule_AddIntConstant(m, "GPT4", GPT4);
        PyModule_AddIntConstant(m, "GPT4F", GPT4F);
        PyModule_AddIntConstant(m, "GPT4H", GPT4H);
        PyModule_AddIntConstant(m, "GPT4OH", GPT4OH);
        PyModule_AddIntConstant(m, "GPT4S", GPT4S);
        PyModule_AddIntConstant(m, "GPT4SH", GPT4SH);
        PyModule_AddIntConstant(m, "GPT5", GPT5);
        PyModule_AddIntConstant(m, "GPT5F", GPT5F);
        PyModule_AddIntConstant(m, "GPT5H", GPT5H);
        PyModule_AddIntConstant(m, "GPT5OH", GPT5OH);
        PyModule_AddIntConstant(m, "GPT5S", GPT5S);
        PyModule_AddIntConstant(m, "GPT5SH", GPT5SH);
        PyModule_AddIntConstant(m, "GPT6", GPT6);
        PyModule_AddIntConstant(m, "GPT6F", GPT6F);
        PyModule_AddIntConstant(m, "GPT6H", GPT6H);
        PyModule_AddIntConstant(m, "GPT6OH", GPT6OH);
        PyModule_AddIntConstant(m, "GPT6S", GPT6S);
        PyModule_AddIntConstant(m, "GPT6SH", GPT6SH);
        PyModule_AddIntConstant(m, "GPT7", GPT7);
        PyModule_AddIntConstant(m, "GPT7F", GPT7F);
        PyModule_AddIntConstant(m, "GPT7H", GPT7H);
        PyModule_AddIntConstant(m, "GPT7OH", GPT7OH);
        PyModule_AddIntConstant(m, "GPT7S", GPT7S);
        PyModule_AddIntConstant(m, "GPT7SH", GPT7SH);
        PyModule_AddIntConstant(m, "GPT8", GPT8);
        PyModule_AddIntConstant(m, "GPT8F", GPT8F);
        PyModule_AddIntConstant(m, "GPT8H", GPT8H);
        PyModule_AddIntConstant(m, "GPT8OH", GPT8OH);
        PyModule_AddIntConstant(m, "GPT8S", GPT8S);
        PyModule_AddIntConstant(m, "GPT8SH", GPT8SH);
        PyModule_AddIntConstant(m, "CMTR1", CMTR1);
        PyModule_AddIntConstant(m, "CMTR1H", CMTR1H);
        PyModule_AddIntConstant(m, "CMTR1L", CMTR1L);
        PyModule_AddIntConstant(m, "CMTR1V", CMTR1V);
        PyModule_AddIntConstant(m, "CMTR1R", CMTR1R);
        PyModule_AddIntConstant(m, "CMTR2", CMTR2);
        PyModule_AddIntConstant(m, "CMTR2H", CMTR2H);
        PyModule_AddIntConstant(m, "CMTR2L", CMTR2L);
        PyModule_AddIntConstant(m, "CMTR2V", CMTR2V);
        PyModule_AddIntConstant(m, "CMTR2R", CMTR2R);
        PyModule_AddIntConstant(m, "CMTR3", CMTR3);
        PyModule_AddIntConstant(m, "CMTR3H", CMTR3H);
        PyModule_AddIntConstant(m, "CMTR3L", CMTR3L);
        PyModule_AddIntConstant(m, "CMTR3V", CMTR3V);
        PyModule_AddIntConstant(m, "CMTR3R", CMTR3R);
        PyModule_AddIntConstant(m, "CMTR4", CMTR4);
        PyModule_AddIntConstant(m, "CMTR4H", CMTR4H);
        PyModule_AddIntConstant(m, "CMTR4L", CMTR4L);
        PyModule_AddIntConstant(m, "CMTR4V", CMTR4V);
        PyModule_AddIntConstant(m, "CMTR4R", CMTR4R);
        PyModule_AddIntConstant(m, "IMTR1", IMTR1);
        PyModule_AddIntConstant(m, "IMTR1H", IMTR1H);
        PyModule_AddIntConstant(m, "IMTR1L", IMTR1L);
        PyModule_AddIntConstant(m, "IMTR2", IMTR2);
        PyModule_AddIntConstant(m, "IMTR2H", IMTR2H);
        PyModule_AddIntConstant(m, "IMTR2L", IMTR2L);
        PyModule_AddIntConstant(m, "IMTR3", IMTR3);
        PyModule_AddIntConstant(m, "IMTR3H", IMTR3H);
        PyModule_AddIntConstant(m, "IMTR3L", IMTR3L);
        PyModule_AddIntConstant(m, "IMTR4", IMTR4);
        PyModule_AddIntConstant(m, "IMTR4H", IMTR4H);
        PyModule_AddIntConstant(m, "IMTR4L", IMTR4L);
        PyModule_AddIntConstant(m, "VMTR1", VMTR1);
        PyModule_AddIntConstant(m, "VMTR1H", VMTR1H);
        PyModule_AddIntConstant(m, "VMTR1L", VMTR1L);
        PyModule_AddIntConstant(m, "VMTR2", VMTR2);
        PyModule_AddIntConstant(m, "VMTR2H", VMTR2H);
        PyModule_AddIntConstant(m, "VMTR2L", VMTR2L);
        PyModule_AddIntConstant(m, "VMTR3", VMTR3);
        PyModule_AddIntConstant(m, "VMTR3H", VMTR3H);
        PyModule_AddIntConstant(m, "VMTR3L", VMTR3L);
        PyModule_AddIntConstant(m, "VMTR4", VMTR4);
        PyModule_AddIntConstant(m, "VMTR4H", VMTR4H);
        PyModule_AddIntConstant(m, "VMTR4L", VMTR4L);
        PyModule_AddIntConstant(m, "VSRC1", VSRC1);
        PyModule_AddIntConstant(m, "VSRC1H", VSRC1H);
        PyModule_AddIntConstant(m, "VSRC1L", VSRC1L);
        PyModule_AddIntConstant(m, "VSRC2", VSRC2);
        PyModule_AddIntConstant(m, "VSRC2H", VSRC2H);
        PyModule_AddIntConstant(m, "VSRC2L", VSRC2L);
        PyModule_AddIntConstant(m, "VSRC3", VSRC3);
        PyModule_AddIntConstant(m, "VSRC3H", VSRC3H);
        PyModule_AddIntConstant(m, "VSRC3L", VSRC3L);
        PyModule_AddIntConstant(m, "VSRC4", VSRC4);
        PyModule_AddIntConstant(m, "VSRC4H", VSRC4H);
        PyModule_AddIntConstant(m, "VSRC4L", VSRC4L);
        PyModule_AddIntConstant(m, "VSRC5", VSRC5);
        PyModule_AddIntConstant(m, "VSRC5H", VSRC5H);
        PyModule_AddIntConstant(m, "VSRC5L", VSRC5L);
        PyModule_AddIntConstant(m, "VSRC6", VSRC6);
        PyModule_AddIntConstant(m, "VSRC6H", VSRC6H);
        PyModule_AddIntConstant(m, "VSRC6L", VSRC6L);
        PyModule_AddIntConstant(m, "VSRC7", VSRC7);
        PyModule_AddIntConstant(m, "VSRC7H", VSRC7H);
        PyModule_AddIntConstant(m, "VSRC7L", VSRC7L);
        PyModule_AddIntConstant(m, "VSRC8", VSRC8);
        PyModule_AddIntConstant(m, "VSRC8H", VSRC8H);
        PyModule_AddIntConstant(m, "VSRC8L", VSRC8L);
        PyModule_AddIntConstant(m, "ISRC1", ISRC1);
        PyModule_AddIntConstant(m, "ISRC1H", ISRC1H);
        PyModule_AddIntConstant(m, "ISRC1L", ISRC1L);
        PyModule_AddIntConstant(m, "ISRC2", ISRC2);
        PyModule_AddIntConstant(m, "ISRC2H", ISRC2H);
        PyModule_AddIntConstant(m, "ISRC2L", ISRC2L);
        PyModule_AddIntConstant(m, "ISRC3", ISRC3);
        PyModule_AddIntConstant(m, "ISRC3H", ISRC3H);
        PyModule_AddIntConstant(m, "ISRC3L", ISRC3L);
        PyModule_AddIntConstant(m, "ISRC4", ISRC4);
        PyModule_AddIntConstant(m, "ISRC4H", ISRC4H);
        PyModule_AddIntConstant(m, "ISRC4L", ISRC4L);
        PyModule_AddIntConstant(m, "SIO1", SIO1);
        PyModule_AddIntConstant(m, "SIO2", SIO2);
        PyModule_AddIntConstant(m, "SIO3", SIO3);
        PyModule_AddIntConstant(m, "SIO4", SIO4);
        PyModule_AddIntConstant(m, "SIO5", SIO5);
        PyModule_AddIntConstant(m, "SIO6", SIO6);
        PyModule_AddIntConstant(m, "PIO1", PIO1);
        PyModule_AddIntConstant(m, "PIO2", PIO2);
        PyModule_AddIntConstant(m, "PIO3", PIO3);
        PyModule_AddIntConstant(m, "PIO4", PIO4);
        PyModule_AddIntConstant(m, "PIO5", PIO5);
        PyModule_AddIntConstant(m, "PIO6", PIO6);
        PyModule_AddIntConstant(m, "PIO7", PIO7);
        PyModule_AddIntConstant(m, "PIO8", PIO8);
        PyModule_AddIntConstant(m, "PIO9", PIO9);
        PyModule_AddIntConstant(m, "PIO10", PIO10);
        PyModule_AddIntConstant(m, "TIMER1", TIMER1);
        PyModule_AddIntConstant(m, "TIMER2", TIMER2);
        PyModule_AddIntConstant(m, "TIMER3", TIMER3);
        PyModule_AddIntConstant(m, "TIMER4", TIMER4);
        PyModule_AddIntConstant(m, "PRBR1", PRBR1);
        PyModule_AddIntConstant(m, "PROBER1", PROBER1);
        PyModule_AddIntConstant(m, "PRBR2", PRBR2);
        PyModule_AddIntConstant(m, "PROBER2", PROBER2);
        PyModule_AddIntConstant(m, "PRBR3", PRBR3);
        PyModule_AddIntConstant(m, "PROBER3", PROBER3);
        PyModule_AddIntConstant(m, "PRBR4", PRBR4);
        PyModule_AddIntConstant(m, "PROBER4", PROBER4);
        PyModule_AddIntConstant(m, "FAKE", FAKE);
        PyModule_AddIntConstant(m, "FAKE1", FAKE1);
        PyModule_AddIntConstant(m, "FAKE2", FAKE2);
        PyModule_AddIntConstant(m, "FAKE3", FAKE3);
        PyModule_AddIntConstant(m, "FAKE4", FAKE4);
        PyModule_AddIntConstant(m, "MTRX1", MTRX1);
        PyModule_AddIntConstant(m, "MATRIX1", MATRIX1);
        PyModule_AddIntConstant(m, "MTRX2", MTRX2);
        PyModule_AddIntConstant(m, "MATRIX2", MATRIX2);
        PyModule_AddIntConstant(m, "MTRX3", MTRX3);
        PyModule_AddIntConstant(m, "MATRIX3", MATRIX3);
        PyModule_AddIntConstant(m, "MTRX4", MTRX4);
        PyModule_AddIntConstant(m, "MATRIX4", MATRIX4);
        PyModule_AddIntConstant(m, "GPI1", GPI1);
        PyModule_AddIntConstant(m, "GPI1H", GPI1H);
        PyModule_AddIntConstant(m, "GPI1L", GPI1L);
        PyModule_AddIntConstant(m, "GPI1SH", GPI1SH);
        PyModule_AddIntConstant(m, "GPI1SL", GPI1SL);
        PyModule_AddIntConstant(m, "GPI2", GPI2);
        PyModule_AddIntConstant(m, "GPI2H", GPI2H);
        PyModule_AddIntConstant(m, "GPI2L", GPI2L);
        PyModule_AddIntConstant(m, "GPI2SH", GPI2SH);
        PyModule_AddIntConstant(m, "GPI2SL", GPI2SL);
        PyModule_AddIntConstant(m, "GPI3", GPI3);
        PyModule_AddIntConstant(m, "GPI3H", GPI3H);
        PyModule_AddIntConstant(m, "GPI3L", GPI3L);
        PyModule_AddIntConstant(m, "GPI3SH", GPI3SH);
        PyModule_AddIntConstant(m, "GPI3SL", GPI3SL);
        PyModule_AddIntConstant(m, "GPI4", GPI4);
        PyModule_AddIntConstant(m, "GPI4H", GPI4H);
        PyModule_AddIntConstant(m, "GPI4L", GPI4L);
        PyModule_AddIntConstant(m, "GPI4SH", GPI4SH);
        PyModule_AddIntConstant(m, "GPI4SL", GPI4SL);
        PyModule_AddIntConstant(m, "GPI5", GPI5);
        PyModule_AddIntConstant(m, "GPI5H", GPI5H);
        PyModule_AddIntConstant(m, "GPI5L", GPI5L);
        PyModule_AddIntConstant(m, "GPI5SH", GPI5SH);
        PyModule_AddIntConstant(m, "GPI5SL", GPI5SL);
        PyModule_AddIntConstant(m, "GPI6", GPI6);
        PyModule_AddIntConstant(m, "GPI6H", GPI6H);
        PyModule_AddIntConstant(m, "GPI6L", GPI6L);
        PyModule_AddIntConstant(m, "GPI6SH", GPI6SH);
        PyModule_AddIntConstant(m, "GPI6SL", GPI6SL);
        PyModule_AddIntConstant(m, "GPI7", GPI7);
        PyModule_AddIntConstant(m, "GPI7H", GPI7H);
        PyModule_AddIntConstant(m, "GPI7L", GPI7L);
        PyModule_AddIntConstant(m, "GPI7SH", GPI7SH);
        PyModule_AddIntConstant(m, "GPI7SL", GPI7SL);
        PyModule_AddIntConstant(m, "GPI8", GPI8);
        PyModule_AddIntConstant(m, "GPI8H", GPI8H);
        PyModule_AddIntConstant(m, "GPI8L", GPI8L);
        PyModule_AddIntConstant(m, "GPI8SH", GPI8SH);
        PyModule_AddIntConstant(m, "GPI8SL", GPI8SL);
        PyModule_AddIntConstant(m, "PGU1", PGU1);
        PyModule_AddIntConstant(m, "PGU2", PGU2);
        PyModule_AddIntConstant(m, "PGU3", PGU3);
        PyModule_AddIntConstant(m, "PGU4", PGU4);
        PyModule_AddIntConstant(m, "PGU5", PGU5);
        PyModule_AddIntConstant(m, "PGU6", PGU6);
        PyModule_AddIntConstant(m, "PGU7", PGU7);
        PyModule_AddIntConstant(m, "PGU8", PGU8);
        PyModule_AddIntConstant(m, "PGU9", PGU9);
        PyModule_AddIntConstant(m, "PGU10", PGU10);
        PyModule_AddIntConstant(m, "PGU11", PGU11);
        PyModule_AddIntConstant(m, "PGU12", PGU12);
        PyModule_AddIntConstant(m, "PGU13", PGU13);
        PyModule_AddIntConstant(m, "PGU14", PGU14);
        PyModule_AddIntConstant(m, "PGU15", PGU15);
        PyModule_AddIntConstant(m, "PGU16", PGU16);
        PyModule_AddIntConstant(m, "VPU1", VPU1);
        PyModule_AddIntConstant(m, "VPU1CH1", VPU1CH1);
        PyModule_AddIntConstant(m, "VPU1CH2", VPU1CH2);
        PyModule_AddIntConstant(m, "VPU2", VPU2);
        PyModule_AddIntConstant(m, "VPU2CH1", VPU2CH1);
        PyModule_AddIntConstant(m, "VPU2CH2", VPU2CH2);
        PyModule_AddIntConstant(m, "VPU3", VPU3);
        PyModule_AddIntConstant(m, "VPU3CH1", VPU3CH1);
        PyModule_AddIntConstant(m, "VPU3CH2", VPU3CH2);
        PyModule_AddIntConstant(m, "VPU4", VPU4);
        PyModule_AddIntConstant(m, "VPU4CH1", VPU4CH1);
        PyModule_AddIntConstant(m, "VPU4CH2", VPU4CH2);
        PyModule_AddIntConstant(m, "VPU5", VPU5);
        PyModule_AddIntConstant(m, "VPU5CH1", VPU5CH1);
        PyModule_AddIntConstant(m, "VPU5CH2", VPU5CH2);
        PyModule_AddIntConstant(m, "VPU6", VPU6);
        PyModule_AddIntConstant(m, "VPU6CH1", VPU6CH1);
        PyModule_AddIntConstant(m, "VPU6CH2", VPU6CH2);
        PyModule_AddIntConstant(m, "VPU7", VPU7);
        PyModule_AddIntConstant(m, "VPU7CH1", VPU7CH1);
        PyModule_AddIntConstant(m, "VPU7CH2", VPU7CH2);
        PyModule_AddIntConstant(m, "VPU8", VPU8);
        PyModule_AddIntConstant(m, "VPU8CH1", VPU8CH1);
        PyModule_AddIntConstant(m, "VPU8CH2", VPU8CH2);
        PyModule_AddIntConstant(m, "VPU9", VPU9);
        PyModule_AddIntConstant(m, "VPU9CH1", VPU9CH1);
        PyModule_AddIntConstant(m, "VPU9CH2", VPU9CH2);
        PyModule_AddIntConstant(m, "VPU10", VPU10);
        PyModule_AddIntConstant(m, "VPU10CH1", VPU10CH1);
        PyModule_AddIntConstant(m, "VPU10CH2", VPU10CH2);
        PyModule_AddIntConstant(m, "VPU11", VPU11);
        PyModule_AddIntConstant(m, "VPU11CH1", VPU11CH1);
        PyModule_AddIntConstant(m, "VPU11CH2", VPU11CH2);
        PyModule_AddIntConstant(m, "VPU12", VPU12);
        PyModule_AddIntConstant(m, "VPU12CH1", VPU12CH1);
        PyModule_AddIntConstant(m, "VPU12CH2", VPU12CH2);
        PyModule_AddIntConstant(m, "VPU13", VPU13);
        PyModule_AddIntConstant(m, "VPU13CH1", VPU13CH1);
        PyModule_AddIntConstant(m, "VPU13CH2", VPU13CH2);
        PyModule_AddIntConstant(m, "VPU14", VPU14);
        PyModule_AddIntConstant(m, "VPU14CH1", VPU14CH1);
        PyModule_AddIntConstant(m, "VPU14CH2", VPU14CH2);
        PyModule_AddIntConstant(m, "VPU15", VPU15);
        PyModule_AddIntConstant(m, "VPU15CH1", VPU15CH1);
        PyModule_AddIntConstant(m, "VPU15CH2", VPU15CH2);
        PyModule_AddIntConstant(m, "VPU16", VPU16);
        PyModule_AddIntConstant(m, "VPU16CH1", VPU16CH1);
        PyModule_AddIntConstant(m, "VPU16CH2", VPU16CH2);
        PyModule_AddIntConstant(m, "PMU1", PMU1);
        PyModule_AddIntConstant(m, "PMU1CH1", PMU1CH1);
        PyModule_AddIntConstant(m, "PMU1CH2", PMU1CH2);
        PyModule_AddIntConstant(m, "PMU2", PMU2);
        PyModule_AddIntConstant(m, "PMU2CH1", PMU2CH1);
        PyModule_AddIntConstant(m, "PMU2CH2", PMU2CH2);
        PyModule_AddIntConstant(m, "PMU3", PMU3);
        PyModule_AddIntConstant(m, "PMU3CH1", PMU3CH1);
        PyModule_AddIntConstant(m, "PMU3CH2", PMU3CH2);
        PyModule_AddIntConstant(m, "PMU4", PMU4);
        PyModule_AddIntConstant(m, "PMU4CH1", PMU4CH1);
        PyModule_AddIntConstant(m, "PMU4CH2", PMU4CH2);
        PyModule_AddIntConstant(m, "PMU5", PMU5);
        PyModule_AddIntConstant(m, "PMU5CH1", PMU5CH1);
        PyModule_AddIntConstant(m, "PMU5CH2", PMU5CH2);
        PyModule_AddIntConstant(m, "PMU6", PMU6);
        PyModule_AddIntConstant(m, "PMU6CH1", PMU6CH1);
        PyModule_AddIntConstant(m, "PMU6CH2", PMU6CH2);
        PyModule_AddIntConstant(m, "PMU7", PMU7);
        PyModule_AddIntConstant(m, "PMU7CH1", PMU7CH1);
        PyModule_AddIntConstant(m, "PMU7CH2", PMU7CH2);
        PyModule_AddIntConstant(m, "PMU8", PMU8);
        PyModule_AddIntConstant(m, "PMU8CH1", PMU8CH1);
        PyModule_AddIntConstant(m, "PMU8CH2", PMU8CH2);
        PyModule_AddIntConstant(m, "PMU9", PMU9);
        PyModule_AddIntConstant(m, "PMU9CH1", PMU9CH1);
        PyModule_AddIntConstant(m, "PMU9CH2", PMU9CH2);
        PyModule_AddIntConstant(m, "PMU10", PMU10);
        PyModule_AddIntConstant(m, "PMU10CH1", PMU10CH1);
        PyModule_AddIntConstant(m, "PMU10CH2", PMU10CH2);
        PyModule_AddIntConstant(m, "PMU11", PMU11);
        PyModule_AddIntConstant(m, "PMU11CH1", PMU11CH1);
        PyModule_AddIntConstant(m, "PMU11CH2", PMU11CH2);
        PyModule_AddIntConstant(m, "PMU12", PMU12);
        PyModule_AddIntConstant(m, "PMU12CH1", PMU12CH1);
        PyModule_AddIntConstant(m, "PMU12CH2", PMU12CH2);
        PyModule_AddIntConstant(m, "PMU13", PMU13);
        PyModule_AddIntConstant(m, "PMU13CH1", PMU13CH1);
        PyModule_AddIntConstant(m, "PMU13CH2", PMU13CH2);
        PyModule_AddIntConstant(m, "PMU14", PMU14);
        PyModule_AddIntConstant(m, "PMU14CH1", PMU14CH1);
        PyModule_AddIntConstant(m, "PMU14CH2", PMU14CH2);
        PyModule_AddIntConstant(m, "PMU15", PMU15);
        PyModule_AddIntConstant(m, "PMU15CH1", PMU15CH1);
        PyModule_AddIntConstant(m, "PMU15CH2", PMU15CH2);
        PyModule_AddIntConstant(m, "PMU16", PMU16);
        PyModule_AddIntConstant(m, "PMU16CH1", PMU16CH1);
        PyModule_AddIntConstant(m, "PMU16CH2", PMU16CH2);
        PyModule_AddIntConstant(m, "OSC1", OSC1);
        PyModule_AddIntConstant(m, "OSC1INP1", OSC1INP1);
        PyModule_AddIntConstant(m, "OSC1INP2", OSC1INP2);
        PyModule_AddIntConstant(m, "OSC2", OSC2);
        PyModule_AddIntConstant(m, "OSC2INP1", OSC2INP1);
        PyModule_AddIntConstant(m, "OSC2INP2", OSC2INP2);
        PyModule_AddIntConstant(m, "OSC3", OSC3);
        PyModule_AddIntConstant(m, "OSC3INP1", OSC3INP1);
        PyModule_AddIntConstant(m, "OSC3INP2", OSC3INP2);
        PyModule_AddIntConstant(m, "OSC4", OSC4);
        PyModule_AddIntConstant(m, "OSC4INP1", OSC4INP1);
        PyModule_AddIntConstant(m, "OSC4INP2", OSC4INP2);
        PyModule_AddIntConstant(m, "OSC5", OSC5);
        PyModule_AddIntConstant(m, "OSC5INP1", OSC5INP1);
        PyModule_AddIntConstant(m, "OSC5INP2", OSC5INP2);
        PyModule_AddIntConstant(m, "OSC6", OSC6);
        PyModule_AddIntConstant(m, "OSC6INP1", OSC6INP1);
        PyModule_AddIntConstant(m, "OSC6INP2", OSC6INP2);
        PyModule_AddIntConstant(m, "OSC7", OSC7);
        PyModule_AddIntConstant(m, "OSC7INP1", OSC7INP1);
        PyModule_AddIntConstant(m, "OSC7INP2", OSC7INP2);
        PyModule_AddIntConstant(m, "OSC8", OSC8);
        PyModule_AddIntConstant(m, "OSC8INP1", OSC8INP1);
        PyModule_AddIntConstant(m, "OSC8INP2", OSC8INP2);
        PyModule_AddIntConstant(m, "GPIB1", GPIB1);
        PyModule_AddIntConstant(m, "GPIB2", GPIB2);
        PyModule_AddIntConstant(m, "GPIB3", GPIB3);
        PyModule_AddIntConstant(m, "GPIB4", GPIB4);
        PyModule_AddIntConstant(m, "TF1", TF1);
        PyModule_AddIntConstant(m, "FOHM1", FOHM1);
        PyModule_AddIntConstant(m, "FOHM2", FOHM2);
        PyModule_AddIntConstant(m, "FOHM3", FOHM3);
        PyModule_AddIntConstant(m, "FOHM4", FOHM4);
        PyModule_AddIntConstant(m, "FOHM5", FOHM5);
        PyModule_AddIntConstant(m, "FOHM6", FOHM6);
        PyModule_AddIntConstant(m, "FOHM7", FOHM7);
        PyModule_AddIntConstant(m, "FOHM8", FOHM8);
        PyModule_AddIntConstant(m, "FOHMTERM", FOHMTERM);
        PyModule_AddIntConstant(m, "KI_UNKINS", KI_UNKINS);
        PyModule_AddIntConstant(m, "BEEPER1", BEEPER1);
        PyModule_AddIntConstant(m, "BEEPER2", BEEPER2);
        PyModule_AddIntConstant(m, "BEEPER3", BEEPER3);
        PyModule_AddIntConstant(m, "BEEPER4", BEEPER4);
        PyModule_AddIntConstant(m, "ES1", ES1);
        PyModule_AddIntConstant(m, "ES2", ES2);
        PyModule_AddIntConstant(m, "ES3", ES3);
        PyModule_AddIntConstant(m, "ES4", ES4);
        PyModule_AddIntConstant(m, "CVU1", CVU1);
        PyModule_AddIntConstant(m, "CVU1HPOT", CVU1HPOT);
        PyModule_AddIntConstant(m, "CVU1HCUR", CVU1HCUR);
        PyModule_AddIntConstant(m, "CVU1LCUR", CVU1LCUR);
        PyModule_AddIntConstant(m, "CVU1LPOT", CVU1LPOT);
        PyModule_AddIntConstant(m, "CVU2", CVU2);
        PyModule_AddIntConstant(m, "CVU2HPOT", CVU2HPOT);
        PyModule_AddIntConstant(m, "CVU2HCUR", CVU2HCUR);
        PyModule_AddIntConstant(m, "CVU2LCUR", CVU2LCUR);
        PyModule_AddIntConstant(m, "CVU2LPOT", CVU2LPOT);
        PyModule_AddIntConstant(m, "CVU3", CVU3);
        PyModule_AddIntConstant(m, "CVU3HPOT", CVU3HPOT);
        PyModule_AddIntConstant(m, "CVU3HCUR", CVU3HCUR);
        PyModule_AddIntConstant(m, "CVU3LCUR", CVU3LCUR);
        PyModule_AddIntConstant(m, "CVU3LPOT", CVU3LPOT);
        PyModule_AddIntConstant(m, "CVU4", CVU4);
        PyModule_AddIntConstant(m, "CVU4HPOT", CVU4HPOT);
        PyModule_AddIntConstant(m, "CVU4HCUR", CVU4HCUR);
        PyModule_AddIntConstant(m, "CVU4LCUR", CVU4LCUR);
        PyModule_AddIntConstant(m, "CVU4LPOT", CVU4LPOT);
        PyModule_AddIntConstant(m, "CVU5", CVU5);
        PyModule_AddIntConstant(m, "CVU5HPOT", CVU5HPOT);
        PyModule_AddIntConstant(m, "CVU5HCUR", CVU5HCUR);
        PyModule_AddIntConstant(m, "CVU5LCUR", CVU5LCUR);
        PyModule_AddIntConstant(m, "CVU5LPOT", CVU5LPOT);
        PyModule_AddIntConstant(m, "CVU6", CVU6);
        PyModule_AddIntConstant(m, "CVU6HPOT", CVU6HPOT);
        PyModule_AddIntConstant(m, "CVU6HCUR", CVU6HCUR);
        PyModule_AddIntConstant(m, "CVU6LCUR", CVU6LCUR);
        PyModule_AddIntConstant(m, "CVU6LPOT", CVU6LPOT);
        PyModule_AddIntConstant(m, "CVU7", CVU7);
        PyModule_AddIntConstant(m, "CVU7HPOT", CVU7HPOT);
        PyModule_AddIntConstant(m, "CVU7HCUR", CVU7HCUR);
        PyModule_AddIntConstant(m, "CVU7LCUR", CVU7LCUR);
        PyModule_AddIntConstant(m, "CVU7LPOT", CVU7LPOT);
        PyModule_AddIntConstant(m, "CVU8", CVU8);
        PyModule_AddIntConstant(m, "CVU8HPOT", CVU8HPOT);
        PyModule_AddIntConstant(m, "CVU8HCUR", CVU8HCUR);
        PyModule_AddIntConstant(m, "CVU8LCUR", CVU8LCUR);
        PyModule_AddIntConstant(m, "CVU8LPOT", CVU8LPOT);
        PyModule_AddIntConstant(m, "CVU9", CVU9);
        PyModule_AddIntConstant(m, "CVU9HPOT", CVU9HPOT);
        PyModule_AddIntConstant(m, "CVU9HCUR", CVU9HCUR);
        PyModule_AddIntConstant(m, "CVU9LCUR", CVU9LCUR);
        PyModule_AddIntConstant(m, "CVU9LPOT", CVU9LPOT);
        PyModule_AddIntConstant(m, "CVU10", CVU10);
        PyModule_AddIntConstant(m, "CVU10HPOT", CVU10HPOT);
        PyModule_AddIntConstant(m, "CVU10HCUR", CVU10HCUR);
        PyModule_AddIntConstant(m, "CVU10LCUR", CVU10LCUR);
        PyModule_AddIntConstant(m, "CVU10LPOT", CVU10LPOT);
        PyModule_AddIntConstant(m, "CVIV1", CVIV1);
        PyModule_AddIntConstant(m, "CVIV2", CVIV2);
        PyModule_AddIntConstant(m, "REF1", REF1);
        PyModule_AddIntConstant(m, "REF2", REF2);
        PyModule_AddIntConstant(m, "REF3", REF3);
        PyModule_AddIntConstant(m, "VIMS1", VIMS1);
        PyModule_AddIntConstant(m, "VIMS1H", VIMS1H);
        PyModule_AddIntConstant(m, "VIMS1L", VIMS1L);
        PyModule_AddIntConstant(m, "VIMS2", VIMS2);
        PyModule_AddIntConstant(m, "VIMS2H", VIMS2H);
        PyModule_AddIntConstant(m, "VIMS2L", VIMS2L);
        PyModule_AddIntConstant(m, "VIMS3", VIMS3);
        PyModule_AddIntConstant(m, "VIMS3H", VIMS3H);
        PyModule_AddIntConstant(m, "VIMS3L", VIMS3L);
        PyModule_AddIntConstant(m, "VIMS4", VIMS4);
        PyModule_AddIntConstant(m, "VIMS4H", VIMS4H);
        PyModule_AddIntConstant(m, "VIMS4L", VIMS4L);
        PyModule_AddIntConstant(m, "VIMS5", VIMS5);
        PyModule_AddIntConstant(m, "VIMS5H", VIMS5H);
        PyModule_AddIntConstant(m, "VIMS5L", VIMS5L);
        PyModule_AddIntConstant(m, "VIMS6", VIMS6);
        PyModule_AddIntConstant(m, "VIMS6H", VIMS6H);
        PyModule_AddIntConstant(m, "VIMS6L", VIMS6L);
        PyModule_AddIntConstant(m, "VIMS7", VIMS7);
        PyModule_AddIntConstant(m, "VIMS7H", VIMS7H);
        PyModule_AddIntConstant(m, "VIMS7L", VIMS7L);
        PyModule_AddIntConstant(m, "VIMS8", VIMS8);
        PyModule_AddIntConstant(m, "VIMS8H", VIMS8H);
        PyModule_AddIntConstant(m, "VIMS8L", VIMS8L);
        PyModule_AddIntConstant(m, "VIMS9", VIMS9);
        PyModule_AddIntConstant(m, "VIMS9H", VIMS9H);
        PyModule_AddIntConstant(m, "VIMS9L", VIMS9L);
        PyModule_AddIntConstant(m, "VIMS10", VIMS10);
        PyModule_AddIntConstant(m, "VIMS10H", VIMS10H);
        PyModule_AddIntConstant(m, "VIMS10L", VIMS10L);
        PyModule_AddIntConstant(m, "VIMS11", VIMS11);
        PyModule_AddIntConstant(m, "VIMS11H", VIMS11H);
        PyModule_AddIntConstant(m, "VIMS11L", VIMS11L);
        PyModule_AddIntConstant(m, "VIMS12", VIMS12);
        PyModule_AddIntConstant(m, "VIMS12H", VIMS12H);
        PyModule_AddIntConstant(m, "VIMS12L", VIMS12L);
        PyModule_AddIntConstant(m, "VIMS13", VIMS13);
        PyModule_AddIntConstant(m, "VIMS13H", VIMS13H);
        PyModule_AddIntConstant(m, "VIMS13L", VIMS13L);
        PyModule_AddIntConstant(m, "VIMS14", VIMS14);
        PyModule_AddIntConstant(m, "VIMS14H", VIMS14H);
        PyModule_AddIntConstant(m, "VIMS14L", VIMS14L);
        PyModule_AddIntConstant(m, "VIMS15", VIMS15);
        PyModule_AddIntConstant(m, "VIMS15H", VIMS15H);
        PyModule_AddIntConstant(m, "VIMS15L", VIMS15L);
        PyModule_AddIntConstant(m, "VIMS16", VIMS16);
        PyModule_AddIntConstant(m, "VIMS16H", VIMS16H);
        PyModule_AddIntConstant(m, "VIMS16L", VIMS16L);
        PyModule_AddIntConstant(m, "FMTR1", FMTR1);
        PyModule_AddIntConstant(m, "FMTR2", FMTR2);
        PyModule_AddIntConstant(m, "FMTR3", FMTR3);
        PyModule_AddIntConstant(m, "FMTR4", FMTR4);
        PyModule_AddIntConstant(m, "SYMTR", SYMTR);
        PyModule_AddIntConstant(m, "SYMTRH", SYMTRH);
        PyModule_AddIntConstant(m, "SYMTRL", SYMTRL);
        PyModule_AddIntConstant(m, "LCRM", LCRM);
        PyModule_AddIntConstant(m, "PSRC1", PSRC1);
        PyModule_AddIntConstant(m, "PSRC1H", PSRC1H);
        PyModule_AddIntConstant(m, "PSRC1L", PSRC1L);
        PyModule_AddIntConstant(m, "PSRC2", PSRC2);
        PyModule_AddIntConstant(m, "PSRC2H", PSRC2H);
        PyModule_AddIntConstant(m, "PSRC2L", PSRC2L);
        PyModule_AddIntConstant(m, "PSRC3", PSRC3);
        PyModule_AddIntConstant(m, "PSRC3H", PSRC3H);
        PyModule_AddIntConstant(m, "PSRC3L", PSRC3L);
        PyModule_AddIntConstant(m, "PSRC4", PSRC4);
        PyModule_AddIntConstant(m, "PSRC4H", PSRC4H);
        PyModule_AddIntConstant(m, "PSRC4L", PSRC4L);
        PyModule_AddIntConstant(m, "RSRC1", RSRC1);
        PyModule_AddIntConstant(m, "RSRC1H", RSRC1H);
        PyModule_AddIntConstant(m, "RSRC1L", RSRC1L);
        PyModule_AddIntConstant(m, "RSRC2", RSRC2);
        PyModule_AddIntConstant(m, "RSRC2H", RSRC2H);
        PyModule_AddIntConstant(m, "RSRC2L", RSRC2L);
        PyModule_AddIntConstant(m, "RSRC3", RSRC3);
        PyModule_AddIntConstant(m, "RSRC3H", RSRC3H);
        PyModule_AddIntConstant(m, "RSRC3L", RSRC3L);
        PyModule_AddIntConstant(m, "RSRC4", RSRC4);
        PyModule_AddIntConstant(m, "RSRC4H", RSRC4H);
        PyModule_AddIntConstant(m, "RSRC4L", RSRC4L);
        PyModule_AddIntConstant(m, "QSRC1", QSRC1);
        PyModule_AddIntConstant(m, "QSRC1H", QSRC1H);
        PyModule_AddIntConstant(m, "QSRC1L", QSRC1L);
        PyModule_AddIntConstant(m, "QSRC2", QSRC2);
        PyModule_AddIntConstant(m, "QSRC2H", QSRC2H);
        PyModule_AddIntConstant(m, "QSRC2L", QSRC2L);
        PyModule_AddIntConstant(m, "QSRC3", QSRC3);
        PyModule_AddIntConstant(m, "QSRC3H", QSRC3H);
        PyModule_AddIntConstant(m, "QSRC3L", QSRC3L);
        PyModule_AddIntConstant(m, "QSRC4", QSRC4);
        PyModule_AddIntConstant(m, "QSRC4H", QSRC4H);
        PyModule_AddIntConstant(m, "QSRC4L", QSRC4L);
        PyModule_AddIntConstant(m, "IMON1", IMON1);
        PyModule_AddIntConstant(m, "IMON1H", IMON1H);
        PyModule_AddIntConstant(m, "IMON1L", IMON1L);
        PyModule_AddIntConstant(m, "IMON2", IMON2);
        PyModule_AddIntConstant(m, "IMON2H", IMON2H);
        PyModule_AddIntConstant(m, "IMON2L", IMON2L);
        PyModule_AddIntConstant(m, "IMON3", IMON3);
        PyModule_AddIntConstant(m, "IMON3H", IMON3H);
        PyModule_AddIntConstant(m, "IMON3L", IMON3L);
        PyModule_AddIntConstant(m, "IMON4", IMON4);
        PyModule_AddIntConstant(m, "IMON4H", IMON4H);
        PyModule_AddIntConstant(m, "IMON4L", IMON4L);
        PyModule_AddIntConstant(m, "VMON1", VMON1);
        PyModule_AddIntConstant(m, "VMON1H", VMON1H);
        PyModule_AddIntConstant(m, "VMON1L", VMON1L);
        PyModule_AddIntConstant(m, "VMON2", VMON2);
        PyModule_AddIntConstant(m, "VMON2H", VMON2H);
        PyModule_AddIntConstant(m, "VMON2L", VMON2L);
        PyModule_AddIntConstant(m, "VMON3", VMON3);
        PyModule_AddIntConstant(m, "VMON3H", VMON3H);
        PyModule_AddIntConstant(m, "VMON3L", VMON3L);
        PyModule_AddIntConstant(m, "VMON4", VMON4);
        PyModule_AddIntConstant(m, "VMON4H", VMON4H);
        PyModule_AddIntConstant(m, "VMON4L", VMON4L);
        PyModule_AddIntConstant(m, "VMON5", VMON5);
        PyModule_AddIntConstant(m, "VMON5H", VMON5H);
        PyModule_AddIntConstant(m, "VMON5L", VMON5L);
        PyModule_AddIntConstant(m, "VMON6", VMON6);
        PyModule_AddIntConstant(m, "VMON6H", VMON6H);
        PyModule_AddIntConstant(m, "VMON6L", VMON6L);
        PyModule_AddIntConstant(m, "VMON7", VMON7);
        PyModule_AddIntConstant(m, "VMON7H", VMON7H);
        PyModule_AddIntConstant(m, "VMON7L", VMON7L);
        PyModule_AddIntConstant(m, "VMON8", VMON8);
        PyModule_AddIntConstant(m, "VMON8H", VMON8H);
        PyModule_AddIntConstant(m, "VMON8L", VMON8L);
        PyModule_AddIntConstant(m, "QMTR1", QMTR1);
        PyModule_AddIntConstant(m, "QMTR1H", QMTR1H);
        PyModule_AddIntConstant(m, "QMTR1L", QMTR1L);
        PyModule_AddIntConstant(m, "QMTR2", QMTR2);
        PyModule_AddIntConstant(m, "QMTR2H", QMTR2H);
        PyModule_AddIntConstant(m, "QMTR2L", QMTR2L);
        PyModule_AddIntConstant(m, "QMTR3", QMTR3);
        PyModule_AddIntConstant(m, "QMTR3H", QMTR3H);
        PyModule_AddIntConstant(m, "QMTR3L", QMTR3L);
        PyModule_AddIntConstant(m, "QMTR4", QMTR4);
        PyModule_AddIntConstant(m, "QMTR4H", QMTR4H);
        PyModule_AddIntConstant(m, "QMTR4L", QMTR4L);
        PyModule_AddIntConstant(m, "RMTR1", RMTR1);
        PyModule_AddIntConstant(m, "RMTR1H", RMTR1H);
        PyModule_AddIntConstant(m, "RMTR1L", RMTR1L);
        PyModule_AddIntConstant(m, "RMTR1SH", RMTR1SH);
        PyModule_AddIntConstant(m, "RMTR1SL", RMTR1SL);
        PyModule_AddIntConstant(m, "RMTR2", RMTR2);
        PyModule_AddIntConstant(m, "RMTR2H", RMTR2H);
        PyModule_AddIntConstant(m, "RMTR2L", RMTR2L);
        PyModule_AddIntConstant(m, "RMTR2SH", RMTR2SH);
        PyModule_AddIntConstant(m, "RMTR2SL", RMTR2SL);
        PyModule_AddIntConstant(m, "RMTR3", RMTR3);
        PyModule_AddIntConstant(m, "RMTR3H", RMTR3H);
        PyModule_AddIntConstant(m, "RMTR3L", RMTR3L);
        PyModule_AddIntConstant(m, "RMTR3SH", RMTR3SH);
        PyModule_AddIntConstant(m, "RMTR3SL", RMTR3SL);
        PyModule_AddIntConstant(m, "RMTR4", RMTR4);
        PyModule_AddIntConstant(m, "RMTR4H", RMTR4H);
        PyModule_AddIntConstant(m, "RMTR4L", RMTR4L);
        PyModule_AddIntConstant(m, "RMTR4SH", RMTR4SH);
        PyModule_AddIntConstant(m, "RMTR4SL", RMTR4SL);
        PyModule_AddIntConstant(m, "AUXM", AUXM);
        PyModule_AddIntConstant(m, "ACCU1", ACCU1);
        PyModule_AddIntConstant(m, "ACCU1H", ACCU1H);
        PyModule_AddIntConstant(m, "ACCU1L", ACCU1L);
        PyModule_AddIntConstant(m, "JUMPER", JUMPER);
        PyModule_AddIntConstant(m, "SRU1", SRU1);
        PyModule_AddIntConstant(m, "SRU2", SRU2);
        PyModule_AddIntConstant(m, "SRU3", SRU3);
        PyModule_AddIntConstant(m, "SRU4", SRU4);
        PyModule_AddIntConstant(m, "SRU5", SRU5);
        PyModule_AddIntConstant(m, "SRU6", SRU6);
        PyModule_AddIntConstant(m, "SRU7", SRU7);
        PyModule_AddIntConstant(m, "SRU8", SRU8);
        PyModule_AddIntConstant(m, "UNUSED_PINS", UNUSED_PINS);
    }

} // namespace module


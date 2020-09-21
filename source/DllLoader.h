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

#pragma once

//-----------------------------------------------------------------------------

#include <stdexcept>
#include <string>

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>

namespace utils
{
    //-----------------------------------------------------------------------------

    /// <summary>
    /// DLL loader class.
    /// </summary>
    class DllLoader
    {
    public:

        /// <summary>
        /// Creates a new instance.
        /// </summary>
        DllLoader();

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~DllLoader();

        /// <summary>
        /// Loads a DLL.
        /// </summary>
        /// <param name="dllName">The DLL name.</param>
        void Load(const std::string & dllName);

        /// <summary>
        /// Unloads the DLL.
        /// </summary>
        void Free();

        /// <summary>
        /// Returns true if a DLL is loaded.
        /// </summary>
        /// <returns>True if DLL is loaded.</returns>
        bool IsLoaded() const;

        /// <summary>
        /// Retrieves a DLL function pointer.
        /// </summary>
        /// <param name="funcPtr">A variable that stores the DLL function pointer.</param>
        /// <param name="funcName">The DLL function name.</param>
        template <typename T_FuncPtr>
        void GetDllFunc(T_FuncPtr & funcPtr, const std::string & funcName)
        {
            if (!_dll)
                throw std::runtime_error("DllLoader: can not get DLL function pointer, DLL is not loaded!");

            funcPtr = (T_FuncPtr)GetProcAddress(_dll, funcName.c_str());
            if (!funcPtr)
                throw std::runtime_error("DllLoader: function " + funcName + " not found in DLL " + _dllName);
        }

        /// <summary>
        /// Returns the handle oof the loaded DLL.
        /// </summary>
        /// <returns>The DLL handle.</returns>
        const void * GetDllHandle() { return _dll; }

    private:

        HMODULE     _dll;
        std::string _dllName;

    };

    //-----------------------------------------------------------------------------

} // namespace utils


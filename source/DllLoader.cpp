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

#include "DllLoader.h"

#include "WindowsErrorMessage.h"

//-----------------------------------------------------------------------------
namespace utils
{
    //-----------------------------------------------------------------------------

    DllLoader::DllLoader()
    {
        _dll = nullptr;
    }

    //-----------------------------------------------------------------------------

    DllLoader::~DllLoader()
    {
        Free();
    }

    //-----------------------------------------------------------------------------

    bool DllLoader::IsLoaded() const
    {
        return _dll != nullptr;
    }

    //-----------------------------------------------------------------------------

    void DllLoader::Load(const std::string & dllName)
    {
        if (_dll)
            Free();

        _dll = LoadLibrary(dllName.c_str());
        if (!_dll)
            throw std::runtime_error("DllLoader: can not load DLL " + dllName + " (" + WindowsErrorMessage::Translate(GetLastError()) + ")");

        _dllName = dllName;

    }

    //-----------------------------------------------------------------------------

    void DllLoader::Free()
    {
        if (_dll)
        {
            if (!FreeLibrary(_dll))
                throw std::runtime_error("DllLoader: can not free DLL: " + _dllName);

            _dll = nullptr;
            _dllName.clear();
        }
    }

    //-----------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------

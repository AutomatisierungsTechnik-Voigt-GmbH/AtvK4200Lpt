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

#include "WindowsErrorMessage.h"

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>

using namespace std;

namespace utils
{
    //-----------------------------------------------------------------------------

    std::string WindowsErrorMessage::Translate(unsigned int errorCode)
    {
        string errStr;
        LPTSTR s;

        if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_FROM_SYSTEM,
            NULL, errorCode, 0, (LPTSTR)&s, 0, nullptr))
        {
            LPTSTR p = strchr(s, '\r');

            if (p != nullptr)
                *p = '\0';

            errStr = s;
            LocalFree(s);
        }
        else
        {
            errStr = "unknown error";
        }

        return errStr;
    }

    //-----------------------------------------------------------------------------

} // namespace utils

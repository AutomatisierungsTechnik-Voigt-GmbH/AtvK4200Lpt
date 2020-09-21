# Copyright (C) 2020 Torsten Brischalle
# 
# AutomatisierungsTechnik Voigt GmbH
# Heilbronner Str. 17
# 01189 Dresden
# Germany
# 
# web:   https://www.atv-systems.de
# email: atv@atv-systems.de
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
#
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
# LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
# WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

from distutils.core import setup, Extension

moduleLptLibrary = Extension('k4200lptlibrary',
                    sources = ['source/K4200ModuleLptLibrary.cpp',
							   'source/K4200ModuleLptLibraryFunctions.cpp',
							   'source/K4200LptLibrary.cpp',
							   'source/K4200Errors.cpp',
							   'source/WindowsErrorMessage.cpp',
							   'source/DllLoader.cpp',
                               'source/PythonHelper.cpp'])

moduleInstruments = Extension('k4200instruments',
                    sources = ['source/K4200ModuleInstruments.cpp',
                               'source/PythonHelper.cpp'])

moduleParameters = Extension('k4200parameters',
                    sources = ['source/K4200ModuleParameters.cpp',
                               'source/PythonHelper.cpp'])

# can be HTML
longDescription = ""

setup (name = 'AtvK4200Lpt',
       version = '1.0',
       description = 'Python support for K4200 lpt library.',
       author='Torsten Brischalle, Automatisierungstechnik Voigt GmbH',
       author_email='atv@atv-systems.de',
       url='https://www.atv-systems.de',
#       long_description = longDescription,
       ext_modules = [moduleLptLibrary, moduleInstruments, moduleParameters])
       
       
       
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

#import foreign functions
import ctypes

# enums for constants
from enum import IntEnum

class MessageBoxType(IntEnum):
    """
    Message box button type definitions.
    """
    Ok = 0
    OkCancel = 1
    YesNoCancel = 3
    YesNo = 4
    RetryCancel = 5
    
class MessageBoxReturn(IntEnum):
    """
    Message box button return type definitions.
    """
    Ok = 1
    Cancel = 2
    Retry = 4
    Yes = 6
    No = 7
    
def ShowMessageBox(caption, text, msgBoxType):
    """
    Shows a message box.

    :param caption: The message box title.
    :param text: The message box text.
    :param msgBoxType: The mesage box type (which buttons shall be displayed).
    :return: The code of the pressed button.
    """
    return ctypes.windll.user32.MessageBoxW(0, text, caption, msgBoxType)


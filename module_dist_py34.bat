@rmdir /Q /S build
@rmdir /Q /S dist

@SET PYTHONHOME=C:\Python34
@SET PYTHONEXE=%PYTHONHOME%\python.exe
@SET PYTHONPATH=

%PYTHONEXE% setup.py build --compiler=msvc --plat-name=win32

%PYTHONEXE% setup.py sdist
%PYTHONEXE% setup.py bdist_wininst

PAUSE

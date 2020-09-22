
@REM Python version list:
@SET PYTHON_VERSIONS=35 36 37 38

@RMDIR /Q /S build
@RMDIR /Q /S dist

@FOR %%V IN (%PYTHON_VERSIONS%) DO @CALL :BuildVersion %%V

python setup.py sdist

@EXIT /b

:BuildVersion

@SET PYTHONHOME=C:\Users\%USERNAME%\AppData\Local\Programs\Python\Python%1-32
@SET PYTHONEXE=%PYTHONHOME%\python.exe
@SET PYTHONPATH=

%PYTHONEXE% setup.py build --compiler=msvc --plat-name=win32

%PYTHONEXE% setup.py bdist_wininst

@EXIT /b




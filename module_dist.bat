rmdir /Q /S build
rmdir /Q /S dist
python setup.py sdist
python setup.py bdist_wininst
REM pause

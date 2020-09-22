@rmdir /Q /S build
@rmdir /Q /S dist

python setup.py build --compiler=msvc --plat-name=win32

python setup.py sdist
python setup.py bdist_wininst

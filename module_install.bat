@rmdir /Q /S build

python setup.py build --compiler=msvc --plat-name=win32

python setup.py install --force

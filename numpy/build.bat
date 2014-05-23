mkdir bin
cd src
python setup.py build
IF exist build (
   cd build
   FOR /D %%i in (*) DO XCOPY "%%i" ..\..\bin /S /Y
   cd ..\..
) ELSE (
   cd ..
)
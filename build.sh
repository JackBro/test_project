#!/bin/bash
cd ./setuptools && ./build.sh && cd ..
cd ./eventlet && ./build.sh && cd ..
cd ./greenlet && ./build.sh && cd ..
cd ./lxml && ./build.sh && cd ..
cd ./m2crypto && ./build.sh && cd ..
cd ./mysql-python && ./build.sh && cd ..
cd ./numpy && ./build.sh && cd ..
cd ./posix-ipc && ./build.sh && cd ..
cd ./pycrypto && ./build.sh && cd ..
cd ./pyopenssl && ./build.sh && cd ..
zip -r binaries.zip **/bin/

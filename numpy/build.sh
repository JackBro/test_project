#!/bin/bash
cd ./src
python setup.py build
rm -rf ../bin
mkdir ../bin
mv ./build/* ../bin/

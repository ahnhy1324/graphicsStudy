#! /bin/bash

echo "Start Building Graphics Demo Code"
cd build
cmake ..
make clean
make
./OpenglDemo

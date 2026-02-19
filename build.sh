#!/bin/sh
cd ./src
cmake -B build;
cmake --build build;
./build/QtChess
#!/bin/sh

rm -rf build/
mkdir -p build/
cd build

# Build the project
cmake -G "Unix Makefiles" -DCMAKE_PREFIX_PATH=$HOME/Qt/6.6.1/gcc_64/ \
-DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..

make

cp ./compile_commands.json ../

./appwifipicker

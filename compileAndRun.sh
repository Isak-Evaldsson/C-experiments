#!/bin/bash

if [ $# -eq 0 ]; then
    echo "No arugments supplied"
    exit 1
fi

echo "Compiling:"
gcc -Wall $1

if [ -f "a.out" ]; then
    echo "Runing program:"
    ./a.out < $2
    rm a.out
else
    exit 2
fi
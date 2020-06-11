#!/bin/bash

if [ $# -eq 0 ]; then
    echo "No stdin file supplied"
    exit 1
fi

echo "Compiling..."
gcc -Wall "stable-marriage.c" "../myLibs/LinkedList.c"

if [ -f "a.out" ]; then
    echo "Runing program..."
    ./a.out < $1 
    rm a.out
    echo "Execution succesfull!"
else
    exit 2
fi
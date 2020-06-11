#!/bin/bash

if [ $# -eq 0 ]; then
    echo "No arugments supplied"
    exit 1
fi
gcc $1

if [ -f "a.out" ]; then
    ./a.out < $2
    rm a.out
else
    exit 2
fi
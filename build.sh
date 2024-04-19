#!/bin/bash

g++ -std=c++20 -g src/main.cxx -Iinclude -Llib -lkrenq-x86_64 -Wl,-rpath=lib -o kbin



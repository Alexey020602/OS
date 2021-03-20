#!/bin/bash
#Run this in terminal
#+ Command to compile c++ program. here i used common one
g++	-c	$PWD/lab1.cpp
g++	-o	$PWD/lab1	$PWD/lab1.o		-lpthread
#$PWD/lab1
#!/bin/bash
#Run this in terminal
#+ Command to compile c++ program. here i used common one
g++	-c	$PWD/Prog1.cpp
g++	-o	$PWD/Prog1	$PWD/Prog1.o		-lpthread
g++	-c	$PWD/lab4.cpp
g++	-o	$PWD/lab4	$PWD/lab4.o		-lpthread
$PWD/lab4
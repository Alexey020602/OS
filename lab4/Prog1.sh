#!/bin/bash
#Run this in terminal
#+ Command to compile c++ program. here i used common one
g++	-c	$PWD/Prog1.cpp
g++	-o	$PWD/Prog1	$PWD/Prog1.o		-lpthread
#$PWD/Prog1
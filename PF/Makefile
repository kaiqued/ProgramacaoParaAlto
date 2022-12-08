#
.DEFAULT_GOAL := all

FILE_OUT = teste.out
F = fileIn.cpp

build: 
	g++ -pthread $(F) -o $(FILE_OUT)

run: $(FILE_OUT)
	clear
	./$(FILE_OUT)


all: build run
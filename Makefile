#
.DEFAULT_GOAL := all

FILE_OUT = teste.out


build: 
	g++ $(F) -o $(FILE_OUT)

run: $(FILE_OUT)
	./$(FILE_OUT)


all: build run
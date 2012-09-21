# Base Makefile for SDL frontend tests.
# Located at root of project directory.
#
# Version 1.0 - 21/09/2012
CXX=g++
EXE=main
INC=include
BIN=bin
SDL=-lSDL -lSDL_image

all:
	cd src && make
	$(CXX) -o $(EXE) -I$(INC) main.cpp $(BIN)/*.o $(SDL)

clean:
	cd src && make clean

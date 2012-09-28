# Concrete Makefile for compilation.
# Located in project source directory.
#
# Version 0.9 - 21/09/2012
CXX=g++
SRC=.
INC=../include
BIN=../bin
CXXFLAGS=-c -O1 -pedantic -W -Wall -I$(INC) -g
CPP_FILES=$(wildcard *.cpp)
OBJ_FILES=$(CPP_FILES:.cpp=.o)

all: $(OBJ_FILES)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) $(SRC)/$< -o $(BIN)/$@

clean:
	rm -f $(BIN)/*.o

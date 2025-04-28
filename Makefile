# Makefile

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

INCLUDES = -Iinclude -Iexternal
SRC = src/LinkedList.cpp main.cpp
TEST_SRC = src/LinkedList.cpp tests/test_LinkedList.cpp

all: main

main: $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o main $(SRC)

test: $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o test $(TEST_SRC)

clean:
	rm -f main test


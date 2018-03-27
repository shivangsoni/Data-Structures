CC=g++
DEV=-Wall -g -std=c++14
OPT=-O3 -std=c++14

.PHONY: all
all: CreateData AVL
 
CreateData: CreateData.cxx json.hpp
	$(CC) $(OPT) CreateData.cxx -o CreateData

BSTSanityCheck: BSTSanityCheck.cxx BST.o
	$(CC) $(DEV) BSTSanityCheck.cxx BST.o -o BSTSanityCheck

AVL: AVLCommands.o
	$(CC) $(DEV) AVLCommands.o -o AVL

BST.o: BST.cpp BST.h
	$(CC) $(DEV) -c BST.cpp
AVLCommands.o: AVLCommands.cpp AVL.h json.hpp
	$(CC) $(DEV) -c AVLCommands.cpp
# Build
.PHONY: clean
clean:
	rm -f *.o
	rm -f *.exe
	rm -rf *dSYM

.PHONY: update
update:
	make clean
	make all

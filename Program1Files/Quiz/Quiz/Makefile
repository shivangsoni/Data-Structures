CC=g++
DEV=-Wall -g -std=c++14
OPT=-O3 -std=c++14

JSON=json.hpp

SORTING_SOURCES=AlgorithmA.cxx AlgorithmB.cxx AlgorithmC.cxx AlgorithmD.cxx createdata.cxx
SORTING_EXE=$(SORTING_SOURCES:.cxx=.exe)

.PHONY: all
all: $(SORTING_EXE)

# Executables
$(SORTING_EXE): %.exe: %.cxx $(JSON)
	$(CC) $(DEV) -o $@ $<

# Build
.PHONY: clean
clean:
	rm -f *.o
	rm -f *.o3
	rm -f *.exe
	rm -rf *.exe.dSYM

.PHONY: update
update:
	make clean
	make all

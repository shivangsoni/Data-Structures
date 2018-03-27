all: buildheap.exe heapsort.exe createheapoperationdata.exe createsortingdata.exe

buildheap.exe: buildheap.o priorityqueue.o
	g++ -o buildheap.exe buildheap.o priorityqueue.o 

buildheap.o: buildheap.cxx json.hpp
	g++ -std=c++14 -c buildheap.cxx

priorityqueue.o: priorityqueue.cpp priorityqueue.h
	g++ -std=c++14 -c priorityqueue.cpp

heapsort.exe: heapsort.o priorityqueue.o
	g++ -o heapsort.exe heapsort.o priorityqueue.o

heapsort.o: heapsort.cxx json.hpp
	g++ -std=c++14 -c heapsort.cxx

createheapoperationdata.exe:createheapoperationdata.o
	g++ -o createheapoperationdata.exe createheapoperationdata.o

createheapoperationdata.o: createheapoperationdata.cxx json.hpp
	g++ -std=c++14 -c createheapoperationdata.cxx

createsortingdata.exe:createsortingdata.o
	g++ -o createsortingdata.exe createsortingdata.o

createsortingdata.o:createsortingdata.cxx json.hpp
	g++ -std=c++14 -c createsortingdata.cxx

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




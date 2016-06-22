all: bank

bank: primer.cpp StrVec.o
	g++ -g --std=c++0x -o bank primer.cpp StrVec.o

StrVec.o: StrVec.h StrVec.cpp
	g++ -g --std=c++0x -c StrVec.cpp

clean: 
	rm -f *.o bank

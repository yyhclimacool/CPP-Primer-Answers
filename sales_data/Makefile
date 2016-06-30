all: main

main: main.cpp Sales_data.o
	g++ -g --std=c++0x -o main main.cpp Sales_data.o

Sales_data.o: Sales_data.h Sales_data.cpp
	g++ -g --std=c++0x -c Sales_data.cpp

clean: 
	rm -f main Sales_data.o

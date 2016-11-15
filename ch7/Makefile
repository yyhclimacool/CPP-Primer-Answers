all: main nodefault

main: main.cpp Sales_data.hpp
	g++ -g -o main -std=c++1y main.cpp
	
nodefault: nodefault.cpp
	g++ -g -o nodefault -std=c++1y nodefault.cpp
	
clean:
	rm -rf main
	rm -rf core*
	rm -rf nodefault
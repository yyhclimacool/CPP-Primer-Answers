all: main employee

main: main.cpp HasPtr.hpp numbered.hpp
	g++ -g -o main main.cpp -std=c++1y
	
employee: employee.cpp
	g++ -g -o employee employee.cpp -std=c++1y
	
clean:
	rm -rf main employee
	rm -rf core*
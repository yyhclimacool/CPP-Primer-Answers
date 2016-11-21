all: main employee

main: main.cpp HasPtr.hpp numbered.hpp
	g++ -g -o main main.cpp
	
employee: employee.cpp
	g++ -g -o employee employee.cpp
	
clean:
	rm -rf main employee
	rm -rf core*
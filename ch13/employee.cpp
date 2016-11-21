#include <iostream>

using namespace std;

class Employee{
	public:
		Employee():id(++base){cout << "base = " << base << "id = " << id << endl;}
		Employee(const string &str):name(str), id(++base){cout << "base = " << base << "id = " << id << endl;}
		Employee(const Employee &rhs):name(rhs.name), id(++base){cout << "base = " << base << "id = " << id << endl;}
		Employee &operator=(const Employee &rhs){
			name = rhs.name;
			id = ++base;
			cout << "base = " << base << "id = " << id << endl;
			return *this;
		}
		~Employee(){
			//--base;
			cout << "base = " << base << "id = " << id << endl;
		}
	private:
		static unsigned base;
		string name;
		unsigned id;
};

unsigned Employee::base = 0;

int main(int argc, char **argv){
	Employee e;
	Employee e1 = e;
	Employee e2(e1);
	return 0;
}
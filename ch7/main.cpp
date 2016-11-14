#include "Sales_data.hpp"
#include "Person.hpp"
#include "Screen.hpp"

using namespace std;

int main(){
	Sales_data item;
	Person p;

	Screen myScreen(5, 5, 'x');
	myScreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	myScreen.display(cout);
	cout << endl;
	return 0;
}
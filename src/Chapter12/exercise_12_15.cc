#include <iostream>
#include <memory>

using namespace std;

using destination = int;
using connection = double;

connection *connect(destination &d) {
    static double dv = 1.0 + d;
    return &dv;
}

void end_connection(connection *c) {
    cout << __func__ << " " << *c << endl;
}

void manage_connect(destination &d) {
    connection *c = connect(d);
    shared_ptr<connection> spc(c, [](connection *c)->void {cout << __func__ << "---" << *c << endl;});
}

int main() {
    destination d(42);
    manage_connect(d);
}

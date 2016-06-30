#include <iostream>
#include <string>

using namespace std;

class SmallInt{
public:
    SmallInt(int i = 0):val(i){
        if ( i < 0 || i > 255 )
            throw out_of_range("Bad SmallInt value");
    }
    operator int(){ return val; }
private:
    size_t val;
};

int main(){
    SmallInt si;
    si = 4;
    cout << si + 3 << endl;
}

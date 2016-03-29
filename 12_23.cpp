#include <iostream>
#include <memory>

using namespace std;

int main(){
        char cha[] = {'a', 'b', 'c', 'd', 'e'};
        char chb[] = {'f', 'g', 'h', 'i', 'j'};
        size_t len = sizeof(cha) + sizeof(chb);
        cout << len << endl;
        char *pch = new char[len];
        for(size_t i = 0; i < len; ++i){
                if(i < sizeof(cha)){
                        *(pch + i) = *(cha + i);
                }else if(i < len)
                        *(pch + i) = *(chb + (i -sizeof(cha)));
        }
        for(size_t i = 0; i < len; ++i)
                cout << *(pch + i) << endl;
}12.23

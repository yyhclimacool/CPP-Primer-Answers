#include <iostream>

int main() {
    int ia[3][4] = { 
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };  

    int (*parr)[4] = ia + 1;
    if ((*parr)[1] == 5)  
        std::cout << "Test OK" << std::endl;

    std::cout << "Use range-based for loop : " << std::endl;
    for (int (&row)[4] : ia) {
        for(int col : row)
            std::cout << col << " ";
        std::cout << std::endl;
    }   

    std::cout << "Use index : " << std::endl;
    for (int row = 0; row != 3; ++row) {
        for (int col = 0; col != 4; ++col)
            std::cout << ia[row][col] << ' ';
        std::cout << std::endl;
    }   

    std::cout << "Use pointer : " << std::endl;
    for (int (*row)[4] = ia; row != ia + 3; ++row) {
        for (int *col = *row; col != *row + 4; ++col)
            std::cout << *col << ' ';
        std::cout << std::endl;
    }   
}

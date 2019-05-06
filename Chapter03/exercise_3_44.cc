#include <iostream>

int main() {
    int ia[3][4] = { 
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };  

    using one_dim_int_array = int[4];
//    typedef int one_dim_int_array[4];

    std::cout << "Use range-based for loop : " << std::endl;
    for (one_dim_int_array &row : ia) {
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
    for (one_dim_int_array *row = ia; row != ia + 3; ++row) {
        for (int *col = *row; col != *row + 4; ++col)
            std::cout << *col << ' ';
        std::cout << std::endl;
    }   
}

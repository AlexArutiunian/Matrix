#include <iostream>
#include <vector>
#include <fstream>

#include "lib/matrix.hpp"

using T = double;
// виртуальный дестуктор не забывать делать!!
int main(){

    size_t n = 3;
    
    matrix::matrix_<T> m(n, {-13, 2, 3, 2, -10, 6, 3, 6, -5}); //, {-13, 2, 3, 2, -10, 6, 3, 6, -5}
    std::cin >> n;
    matrix::math_matrix<T> m2(n);   //-13 2 3 2 -10 6 3 6 -5
    std::cin >> m2;
    m2.triang_form(0.01);
    std::cout << m2 << std::endl;

    T det = m2.det(0.01);
    std::cout << det << std::endl; 

}

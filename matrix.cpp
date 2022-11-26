#include <iostream>
#include <vector>
#include <fstream>

#include "lib/matrix.hpp"

using T = double;

int main(){

    size_t n = 3;
    
   // std::cin >> n;
    matrix::matrix_<T> m(n);
    std::cin >> m;
    m.triang_form(m, 0.01);
    
    T det = m.det(m, 0.01);
    std::cout << det;  // -13 2 3 2 -10 6 3 6 -5  det = 0

}

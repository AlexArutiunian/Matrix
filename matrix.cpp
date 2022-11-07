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
    matrix::matrix_<T> m2(m);
    matrix::matrix_<T> m3 = m;
   // T det = m.det(m);
    m3 = {1, 1, 0, 0, 1, 0, 0, 0, 1};
    m2 = m3;
    m3 += m2;
    std::cout << m2 << m3;

}

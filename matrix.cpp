#include <iostream>
#include <vector>
#include <fstream>

#include "lib/matrix.hpp"

using T = double;

int main(){

    size_t n = 3;
    
    std::cin >> n;
    matrix::matrix_<T> m(n);
    std::cin >> m;
    T det = m.det(m);
    
    std::cout << det;

}

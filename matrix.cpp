#include <iostream>
#include <fstream>

#include "lib/matrix.hpp"

using T = double;

int main(){

    size_t n = 3;
    
    // if  abs(a[i][j]) < EPS, then a[i][j] = 0
    T EPS = 0.001;
    
    std::cin >> n;
    matrix::math_matrix<T> m(n); 
    std::cin >> m;

    T det = m.det(EPS);
    std::cout << det << std::endl; 

}

#include <iostream>
#include <fstream>
#include <vector>

#include "lib/matrix.hpp"

using T = long double;

int main(){

    size_t n = 4;
    
    // if  abs(a[i][j]) < EPS, then a[i][j] = 0
    T EPS = 0.00001;
    
    std::cin >> n;
    matrix::math_matrix<T> m(n);
    std::cin >> m;

    std::cout << m.det_Gauss();
  
    

}

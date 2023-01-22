#include <iostream>
#include <fstream>
#include <vector>

#include "lib/matrix.hpp"

using T = long double;

int main(){

    size_t n = 4;
    
    // if  abs(a[i][j]) < EPS, then a[i][j] = 0
    T EPS = 0.00001;
    int test[10] = {1, 2, 3, 1, 2, 7, 1, 2};
    std::cout << *std::max_element(test + 2, test + 5) << std::endl;
    
  //  std::cin >> n;
    matrix::math_matrix<T> m(n, n);
    std::cin >> m;
    
    T det_B = m.det_Gauss(EPS);
    std::cout << det_B << std::endl;
    std::cout << m << std::endl;

    

 

    

}

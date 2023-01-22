#include <iostream>
#include <fstream>

#include "../../lib/matrix.hpp"

using T = double;

int main(){

    size_t n = 4;
   
    // if  abs(a[i][j]) < EPS, then a[i][j] = 0
    T EPS = 0.0000000001;
    matrix::math_matrix<T> m(n); 
    std::cin >> m;
    for(int i = 0; i != 3; i++){
        std::cout << m.find_max_in_row(i) << std::endl;
    }
    T det = m.det_Bareiss(EPS);
    std::cout << det << std::endl;
    std::cout << m << std::endl;
    
    
    
    

}

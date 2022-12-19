#include <iostream>
#include <fstream>

#include "../../lib/matrix.hpp"

using T = double;

int main(){

    size_t n = 100;
    std::ofstream gen_m("100x100.txt");
    
    // if  abs(a[i][j]) < EPS, then a[i][j] = 0
    T EPS = 0.0000000001;
    matrix::math_matrix<T> m(n);
    
    gen_m << m;    

}

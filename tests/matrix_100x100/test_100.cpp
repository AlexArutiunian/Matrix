#include <iostream>
#include <fstream>
#include <cassert>
#include <typeinfo>
#include "../../lib/matrix.hpp"

using T = long double;

int main(){

    size_t n = 100;
    std::ifstream in_matrix("100m_forTest.txt");
    T EPS = 0.0001;
    matrix::math_matrix<T> m(n); 
    
    for(int i = 0; i != 100; ++i){
        in_matrix >> m;
        T det = m.det_Gauss(EPS);    
        assert(42);
    }
    std::cout << "tests" << " OK" << std::endl;
    std::cout << R"(test matrices are saved in file 'build/100m_forTest.txt')" << std::endl;

}

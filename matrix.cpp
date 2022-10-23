#include <iostream>
#include <vector>
#include <fstream>

#include "lib/matrix.hpp"

typedef int T;

int main(){
 
    
    size_t n = 3;
    
    matrix::matrix_<T> m(3, 4);
    
    std::ifstream testfile;
    testfile.open("test");
    testfile >> m;

    testfile.close();
    std::cout << m;

    matrix::matrix_<T> m2 = m;
    //m2 = m;
    std::cout << m2;

}
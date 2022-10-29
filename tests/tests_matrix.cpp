#include <iostream>
#include <vector>
#include <fstream>
#include "../lib/test_gen.hpp"

#include "../lib/matrix.hpp"

using T = double;

int main(){
 
    
    size_t n = 3;
    T elem;
    int numtests = 100;
    test::test(n, numtests, 10);
    std::ifstream testfile;
    testfile.open("test.1");
    for(int i = 0; i < numtests; ++i){
        testfile >> n;
        matrix::matrix_<T> m(n);
        testfile >> m;
        
        T det = m.det(m);
        std::cout << '\n';
        std::cout << m;
        std::cout << "res " << i + 1 << " = " << det << std::endl;

    }
    testfile.close();
}

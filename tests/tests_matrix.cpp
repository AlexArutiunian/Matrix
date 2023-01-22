#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include "../lib/test_gen.hpp"

#include "../lib/matrix.hpp"

using T = double;

int main(){
 
    auto start = std::chrono::steady_clock::now();
    size_t n = 10;
    T elem;
    int numtests = 100000;
    test::test(n, numtests, 10);
    std::ifstream testfile;
    std::ofstream resfile;
    resfile.open("res.txt");
    testfile.open("test.1");
    for(int i = 0; i < numtests; ++i){
        testfile >> n;
        resfile << i << ")" << std::endl;
        matrix::math_matrix<T> m(n);
        testfile >> m;
        resfile << m;
        
        T det = m.det_Bareiss(0.01);
        resfile << det << '\n';
     /*   std::cout << '\n';
        std::cout << m;
        std::cout << "res " << i + 1 << " = " << det << std::endl;*/

    }
    testfile.close();
    resfile.close();

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "runtime (sec) = " << elapsed_seconds.count() << std::endl;
}

#include <iostream>
#include <fstream>
#include <cassert>

#include <cstdlib>
#include <unistd.h>

#include "../lib/matrix.hpp"

using T = double;

void dot_come(){
    std::cout << '.';
    std::cout.flush();
    usleep(100000); 
}

void dot_out(){
    std::cout << '\b' << ' ' << '\b';
    std::cout.flush();
    usleep(100000);
}

int main(){

    size_t n = 100;
    std::ifstream in_matrix("NxN.txt");
    std::ofstream default_matrix("NxN.txt");

    int number_tests = 10;

    std::cout << "START TESTS (unit matrix transforms into random matrix)" << std::endl;
    
    std::cout << "Input size of square matrix for testing: " << std::endl;
    std::cin >> n;
    std::cout << "Input number of matrixes for testing (recommend more than 100): " << std::endl;
    std::cin >> number_tests;
    
    // if  abs(a[i][j]) < EPS, then a[i][j] = 0
    T EPS = 0.000000000001;
    matrix::math_matrix<T> m(n); 
    default_matrix << m;
    in_matrix >> m;
    
    
    std::ofstream out_matrix("../build/outNxN.txt");
    
    std::cout << "testing in progress";

    for(int i = 0; i != number_tests + 1; ++i){
       
        if(i % 50 == 0){
            dot_come();
            dot_come();
            dot_come();
        }
        if(i % 50 == 0){
            dot_out();
            dot_out();
            dot_out();
        }
        
        
        int row1 = std::rand() % (n + 1);
        int row2 = std::rand() % (n + 1);
        int lyambda = (std::rand() % 3) - 1;
        if(!lyambda) lyambda += 1;
        if(!row1) row1 += 1;
        if(!row2) row2 += 1;

        // posible problem with matrix 2x2

        if((row1 == row2) && (row1 != n)){
            row1 += 1;
            if(row2 == 1){
                row2 += 2;
            }
            else{
                row2 -= 1;
            }
        } 
        if((row1 == row2) && (row1 == n)){
            row1 -= 1;
            row2 -= 2;
            
        }    
        out_matrix <<  i << R"()row numder ")" << row1 << R"(" + row number ")" << row2 <<
        R"(" * )" << lyambda << std::endl;
        m.trd_E(row1, row2, lyambda, EPS); 
        out_matrix << m << std::endl;
        matrix::math_matrix<T> m_copy(n);
        m_copy = m;
        T det = m_copy.det_Gauss();
        
        out_matrix << "Matrix\n" << m_copy << std::endl;
        out_matrix << "det after transfom. : " << det << "\n\n";
        
        if(( det - 1 ) > 0.0001){
            out_matrix << "Error with matrix\n" << m_copy << std::endl;
            out_matrix << "det = " << det << std::endl;
            assert(( det - 1 ) <= 0.0001);
        }
        

    }

    std::cout << "\nTests OK" << std::endl;

    std::cout << "Results are saved in file outNxN.txt";

}

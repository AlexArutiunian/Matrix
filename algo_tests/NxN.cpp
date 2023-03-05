#include <iostream>
#include <fstream>
#include <cassert>

#include "../lib/matrix.hpp"

using T = double;

int main(){

    size_t n = 100;
    std::ifstream in_matrix("NxN.txt");
    std::ofstream default_matrix("NxN.txt");
    
    
    // if  abs(a[i][j]) < EPS, then a[i][j] = 0
    T EPS = 0.000000000001;
    matrix::math_matrix<T> m(n); 
    default_matrix << m;
    in_matrix >> m;
    

    std::ofstream out_matrix("../build/outNxN.txt");
    
    

    for(int i = 0; i != 1000; i++){
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
        
        out_matrix << "triang form:\n" << m_copy << std::endl;
        out_matrix << "det after transfom. : " << det << "\n\n";

        assert(( det - 1 ) <= 0.0001);

    }

    std::cout << "Results are saved in file outNxN.txt";

}

#include <iostream>
#include <fstream>

#include "../../lib/matrix.hpp"

using T = double;

int main(){

    size_t n = 5;
    std::ifstream in_matrix("matrix.txt");
    
    
    // if  abs(a[i][j]) < EPS, then a[i][j] = 0
    T EPS = 0.0000000001;
    matrix::math_matrix<T> m(n); 

    in_matrix >> m;

    std::ofstream out_matrix("out_mB.txt");
    
    // Why dont work with i >= 55???

    for(int i = 0; i != 55; i++){
        int row1 = std::rand() % 6;
        int row2 = std::rand() % 6;
        int lyambda = (std::rand() % 3) - 1;
        if(!lyambda) lyambda += 1;
        if(!row1) row1 += 1;
        if(!row2) row2 += 1;
        if(row1 == row2) row1 += 1;
        out_matrix <<  i << R"()row numder ")" << row1 << R"(" + row number ")" << row2 <<
        R"(" * )" << lyambda << std::endl;
        m.trd_E(row1, row2, lyambda, EPS); 
        out_matrix << m << std::endl;
        matrix::math_matrix<T> m_copy(m);
        T det = m_copy.det_Bareiss(EPS);
        out_matrix << "main element:\n" << m.find_max_() << std::endl;
        out_matrix << "triang form:\n" << m_copy << std::endl;
        out_matrix << "det after transfom. : " << det << "\n\n";
    }
    
    

    T det = m.det_Bareiss(EPS);
    std::cout << det << std::endl; 

    std::ofstream after_3ng_form("after_3ng_form.txt");
    m.triang_form_Gauss_max(EPS);
    after_3ng_form << m;
    

}

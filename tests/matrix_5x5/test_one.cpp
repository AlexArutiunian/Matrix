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
    T det = m.det(EPS);
    std::cout << det << std::endl; 
 

    std::ofstream out_matrix("out_m.txt");
    
    for(int i = 0; i != 50; i++){
        int row1 = std::rand() % 6;
        int row2 = std::rand() % 6;
        int lyambda = (std::rand() % 5) - 2;
        if(!lyambda) lyambda += 1;
        if(!row1) row1 += 1;
        if(!row2) row2 += 1;
        if(row1 == row2) row1 += 1;
        out_matrix <<  i << ") к строке " << row1 << " прибавилась строка " << row2 <<
        " умноженная на " << lyambda << std::endl;
        m.trd_E(row1, row2, lyambda, EPS); 
        out_matrix << m << std::endl;
        matrix::math_matrix<T> m_copy(m);
        det = m_copy.det(EPS);
        out_matrix << "Треугольная форма:\n " << m_copy << std::endl;
        out_matrix << "детерминант после преобразований: " << det << "\n\n";
    }
    
    

    det = m.det(EPS);
    std::cout << det << std::endl; 

    std::ofstream after_3ng_form("after_3ng_form.txt");
    m.triang_form(EPS);
    after_3ng_form << m;
    

}

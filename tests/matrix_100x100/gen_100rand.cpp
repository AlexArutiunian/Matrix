#include <iostream>
#include <fstream>
#include "../../lib/matrix.hpp"

using T = long double;

int main(){

    size_t n = 100;
    std::ifstream in_matrix("100x100.txt");
    
    // abs(a[i][j]) < EPS, then a[i][j] = 0
    T EPS = 0.000000000001;
    matrix::math_matrix<T> m(n); 

    in_matrix >> m;


    std::ofstream out_matrix("100m_forTest.txt");
    
    for(int i = 0; i != 1000; i++){
        int row1 = std::rand() % 101;
        int row2 = std::rand() % 101;
        int lyambda = (std::rand() % 3) - 1;
        if(!lyambda) lyambda += 1;
        if(!row1) row1 += 1;
        if(!row2) row2 += 1;
        if(row1 == row2) row1 += 1;
      
        m.trd_E(row1, row2, lyambda, EPS); 
        if(i > 900) out_matrix << m << '\n';
        
        matrix::math_matrix<T> m_copy(m);
        T det = m_copy.det(EPS);
    
    }

    T det = m.det(EPS);
    std::cout << det << std::endl; 

    std::ofstream after_3ng_form("after_3ng_form.txt");
    m.triang_form(EPS);
    after_3ng_form << m;
    

}

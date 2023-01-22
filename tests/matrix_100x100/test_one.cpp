#include <iostream>
#include <fstream>
#include "../../lib/matrix.hpp"

using T = long double;

int main(){

    size_t n = 100;
    std::ifstream in_matrix("100x100.txt");
    
    // if  abs(a[i][j]) < EPS, then a[i][j] = 0
    T EPS = 0.000000000001;
    matrix::math_matrix<T> m(n); 

    in_matrix >> m;
  //  std::cout << m;

    std::ofstream out_matrix("out_m.txt");
    
    for(int i = 0; i != 1000; i++){
        int row1 = std::rand() % 101;
        int row2 = std::rand() % 101;
        int lyambda = (std::rand() % 3) - 1;
        if(!lyambda) lyambda += 1;
        if(!row1) row1 += 1;
        if(!row2) row2 += 1;
        if(row1 == row2) row1 += 1;
      /*  std::cout <<  i << R"()) row numder ")" << row1 << 
        R"(" + row number ")" << row2 <<
        R"(" * )" << lyambda << std::endl;*/
        m.trd_E(row1, row2, lyambda, EPS); 
      //  std::cout << m;
        matrix::math_matrix<T> m_copy(m);
        T det = m_copy.det_Bareiss(EPS);
     //   std::cout << "Треугольная форма:\n " << m_copy;
     //   std::cout << "determinant after transformatoins: " << det << "\n\n";
    }
    
    out_matrix << m;

    T det = m.det_Bareiss(EPS);
    std::cout << det << std::endl; 

    std::ofstream after_3ng_form("after_3ng_form.txt");
    m.triang_form_Bareiss(EPS);
    after_3ng_form << m;
    

}

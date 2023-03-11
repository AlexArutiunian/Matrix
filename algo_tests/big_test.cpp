#include <iostream>
#include <fstream>
#include <cassert>

#include "../lib/matrix.hpp"

using T = double;

void test(size_t n, int number_tests, std::string filename){
 
    std::ifstream in_matrix("NxN.txt");
    std::ofstream default_matrix("NxN.txt");
       
    // if  abs(a[i][j]) < EPS, then a[i][j] = 0
    T EPS = 0.000000000001;
    matrix::math_matrix<T> m(n); 
    
    
    std::cout << m << std::endl;
    std::ofstream out_matrix(filename);
    
    

    for(int i = 0; i != number_tests + 1; ++i){
        int row1 = std::rand() % (n + 1);
        int row2 = std::rand() % (n + 1);
        int lyambda = (std::rand() % 2) - 1;
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

        

        if(abs(det - 1) >= 0.00001){
            std::cout << "ERROR" << std::endl;
            std::cout << m << std::endl;

            std::cout << "ITS DET = ";

            std::cout << det << std::endl;

            assert(abs( det - 1 ) <= 0.0001);
            
        }
        


    }

    std::cout << "Tests OK with size " << n << std::endl;

    std::cout << "Results are saved in file outNxN.txt" << std::endl;
}

int main(){
    
    for(int i = 3; i != 10; ++i){
        std::string file = "result/out" + std::to_string(i);
        file += ".txt";
        test(i, 100, file);
    }
    for(int i = 10; i != 15; ++i){
        std::string file = "result/out" + std::to_string(i);
        file += ".txt";
        test(i, 200, file);
    }
   
    std::cout << '\n';

    
    
    

}

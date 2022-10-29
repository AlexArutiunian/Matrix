#pragma once 

#include <iostream>

namespace matrix{
template <typename T> class matrix_{
private:
    size_t rows;    
    size_t colons; 
    T * p_matrix;

public:   
    // constuctor for matrix size of NxM
    matrix_(size_t rs, size_t cs){
        rows = rs;
        colons = cs;
        p_matrix = new T[rs * cs];
        
    }     
    // constuctor for matrix size of NxN (square_matrix)
    matrix_(size_t size_m){
        rows = size_m;
        colons = size_m;
        p_matrix = new T[size_m * size_m];
    }

    // copy constructor
    matrix_(const matrix_& other_matrix){
        this->colons = other_matrix.colons;
        this->rows = other_matrix.rows;
        this->p_matrix = new T[other_matrix.colons * other_matrix.rows];
        for(int i = 0; i != other_matrix.rows * other_matrix.colons; ++i){
            this->p_matrix[i] = other_matrix.p_matrix[i];
        }

    }
    
    // destuctor for matrix
    ~matrix_(){
        delete[] p_matrix; 
    }

    // overload operator = 

    matrix_ & operator= (const matrix_& other_m){
        this->colons = other_m.colons;
        this->rows = other_m.rows;
        if(this->p_matrix != nullptr){
            delete[] this->p_matrix;
        }
        this->p_matrix = new T[other_m.colons * other_m.rows];

        for(int i = 0; i != other_m.colons * other_m.rows; ++i){
            this->p_matrix[i] = other_m.p_matrix[i];
        }

        return *this;
    } 

    //overload operator +

    matrix_ & operator+ (const matrix_& other_m){
        for(int i = 0; i != other_m.colons * other_m.rows; ++i){
            this->p_matrix[i] += other_m.p_matrix[i];
        }
        return *this;
    }

    //overload operator -

    matrix_ & operator- (const matrix_& other_m){
        for(int i = 0; i != other_m.colons * other_m.rows; ++i){
            this->p_matrix[i] -= other_m.p_matrix[i];
        }
        return *this;
    }

    // method for elementary transformations 1st type
    // swap rows
    void fst_E(int n1, int n2){
        T temp;
        n1 -= 1;
        n2 -= 1;
        for(int i = 0; i != colons; ++i){
            temp = p_matrix[colons * n1 + i];
            p_matrix[colons * n1 + i] = p_matrix[colons * n2 + i];
            p_matrix[colons * n2 + i] = temp;
        }
    }

    // method for elementary transformations 2nd type
    // row * a, a != 0

    void snd_E(int n, T a){
        n -= 1;
        for(int i = 0; i != colons; ++i){
            p_matrix[colons * n + i] *= a;  
        }
    }

    // method for elementary transformations 3rd type
    // row1 = row1 + row2 * a
    
    void trd_E(int n1, int n2, T a){
        n1 -= 1;
        n2 -= 1;
        for(int i = 0; i != colons; ++i){
            p_matrix[colons * n1 + i] += a * p_matrix[colons * n2 + i];  
        }
    }

    // method to make triangular matrix

    void triang_form(matrix_& m){
        
        if(m.colons == m.rows){
            int n = m.colons;
            for(int i = 0; i != n; ++i){
                for(int j = i + 1; j != n; ++j){
                    if(m.p_matrix[(n + 1) * i] == 0){
                        m.fst_E(j + 1, i + 1);
                    }
                    m.trd_E(j + 1, i + 1, -(m.p_matrix[n * j + i] / m.p_matrix[(n + 1) * i])); 
                }              
            }
        }
        
    }

    // method to know determinant

    T det(const matrix_& m){
        matrix_ M = m;
        M.triang_form(M);
        T det = 0;
        int n = M.colons;
        if(M.p_matrix[0] != 0){
            det = M.p_matrix[0];
            for(int i = 1; i != n; ++i){
            det *= M.p_matrix[(n + 1) * i];
            }
        }  
        else return 0;
        
        return det;
    }


    // method for stream input
    // to overload operator >> 
    matrix_& read(std::istream& is, matrix_& m){
        for(int i = 0; i < m.colons * m.rows; ++i){
            is >> m.p_matrix[i];    
        }
        return m;
    }
    // method for stream output
    // to overload operator <<
    void print(std::ostream& os){
        for(int i = 1; i <= colons * rows; ++i){
            os << p_matrix[i - 1] << " ";  
            if(i % colons == 0) os << '\n';   
        }
    }
};   

// overload operator >>
// with method 'read' in class matrix_
template <typename T>
std::istream& operator>> (std::istream& is, matrix_<T>& m){
    m.read(is, m);
    return is;
} 

// overload operator <<
// with method 'print' in class matrix_
template <typename T>
std::ostream& operator<< (std::ostream& os, matrix_<T>& m){
    m.print(os);
    return os;
}

} // namespace matrix
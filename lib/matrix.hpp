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
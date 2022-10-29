#pragma once

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <unistd.h>

namespace test {

void test(int n, int num_tests, int range){
    std::ofstream myfile;
    myfile.open("test.1");
    
    for(int a = 0; a < num_tests; a++){
        myfile << n << " ";
        for (int i = 0; i < n * n; ++i) {
            int a = std::rand() % range;
            myfile << a << " ";
        }
    }
    myfile.close();
}    
};
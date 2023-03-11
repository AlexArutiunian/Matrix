#include <iostream>
#include <fstream>

int main(){
    int n = 10;
    std::ofstream file("gen_m.txt");
    std::ofstream fileC("gen_Cpp.txt");
    fileC << n;
    fileC << ' ';
    for(int i = 1; i != n * n + 1; ++i){
        int temp = std::rand() % 3 - 2;
        
        
    
        file << temp;
        file << '\n';

        fileC << temp;
        fileC << ' ';
        if(i % 10 == 0)
            fileC << '\n';
            
        

    }
}
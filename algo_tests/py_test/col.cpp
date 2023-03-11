#include <iostream>
#include <fstream>

int main(){
    int n = 100;
    std::ifstream file("010.dat");
    std::ofstream out("gen_m.txt");
    
    file >> n;

    int a[n * n];
    
    for(int i = 0; i != n * n; ++i){
        file >> a[i];
        out << a[i];
        out << '\n';
        
    }
}
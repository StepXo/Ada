#include <iostream>
#include <cmath> 

int main() {
    int contador;   
    long long entrada;  

    std::cin >> contador;  

    for (int i = 0; i < contador; ++i) {
        std::cin >> entrada;  
        long batallón = 2;
        for (long long j = 2; j <= std::sqrt(entrada); ++j) {  
            if (entrada % j == 0) {
                if (j != entrada / j) {
                    batallón+=2;
                } else {
                    batallón++;
                }
            }
        }
        std::cout << batallón << std::endl;
    }

    return 0;
}

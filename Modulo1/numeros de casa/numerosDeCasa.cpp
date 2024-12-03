#include <iostream>
#include <math.h>

int main() {
    
    int contador;
    long long int entrada;

    std::cin >> contador;

    for (int i = 0;i < contador; ++i) {
        std::cin >> entrada;
        double respuesta = std::sqrt((entrada * (entrada + 1)) / 2.0);

        if (std::abs(respuesta - static_cast<long long int>(respuesta)) < 1e-9) {
            std::cout << static_cast<long long int>(respuesta) << std::endl;      
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
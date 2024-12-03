#include <iostream>

int main() {
    int entrada;

    while (true) {
        std::cout << "Ingresa un número (ingresa 0 para salir): ";
        std::cin >> entrada;

        if (entrada == 0) {
            std::cout << "Has salido del bucle." << std::endl;
            break;
        }

        std::cout << "Número ingresado: " << entrada << std::endl;
    }

    return 0;
}

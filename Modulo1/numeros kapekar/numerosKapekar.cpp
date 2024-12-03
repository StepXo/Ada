#include <iostream>
#include <string>

int main() {
    int casos;
    std::cin >> casos;

    long long entrada = 0;


    for (int i = 0; i < casos; i++) {
        long long comparador = 0;
        long long potencia = 1;
        bool ceros = false;
        long long residuo = 0;
        std::cin >> entrada;
        long long cuadrado = entrada * entrada;
        bool esKaprekar = false;

        while (cuadrado > 10){
            if (cuadrado%10 == 0 && residuo == 0){
                ceros = true;
            } else {
                ceros = false;
            }

            residuo = cuadrado%10;
            comparador = comparador + residuo*potencia;
            cuadrado = cuadrado/10;

            long long suma = cuadrado + comparador;

            if (!ceros && suma == entrada) {
                std::cout << "KAP" << std::endl;
                esKaprekar = true;
                break;
            }
            potencia = potencia*10;
        }

        if (!esKaprekar) {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}

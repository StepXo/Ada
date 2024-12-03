#include <iostream>

long long int invert( long long int numero){
    long long int respuesta = 0;
    while (numero > 0) {
        int residuo = numero % 10;
        respuesta = respuesta * 10 + residuo;  
        numero = numero / 10;
    }

    return respuesta;
}

int main() {
    long long int entrada;

    while (true) {
        std::cin >> entrada;
        if (entrada == 0) {
            break;
        }
        long contador = 0;
        bool isCapicua = false;

        while (entrada<1e10){
            long long int inverted = invert(entrada);

            if (inverted == entrada){
                std::cout << contador << std::endl;
                isCapicua = true;
                break;
            }

            entrada = entrada +inverted;
            contador++;
        }

        if (!isCapicua){
            std::cout << "L" << std::endl;
        }
    }

    return 0;
}
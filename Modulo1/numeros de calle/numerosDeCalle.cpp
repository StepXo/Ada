#include <iostream>

int main() {
    int contador;
    long long int entrada;

    while (true) {
        std::cin >> entrada;

        if (entrada == 0) {
            break;
        }

        long long int numerador_k = (entrada * (entrada + 1)*(2*entrada +1));
        contador = 0;
        for ( long long int i = 3; i < entrada; ++i ){
            
            long long int numerador_i = ((i) * (i + 1)*(2*i + 1));
            long long int denominador = (i*(i-1)*(2*i-1));

            long long int respuesta = (numerador_k - numerador_i)%denominador;

            if (respuesta == 0) {
                contador++;
            }
        }
        std::cout << contador << std::endl;
    }

    return 0;
}
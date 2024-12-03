#include <iostream>

long long pow_rest(long long numero,long long potencia){
    long long acumulado = 1;

    for (long long i = 0;i<potencia;i++){
        acumulado = (acumulado * numero)%49999;
    }
    return acumulado;
}

long suma_rest(long n,long k){
    long long acumulado = 0;

    for ( int i = 1; i<= n; i++){
        acumulado = (acumulado + pow_rest(i,k))%49999;

    }
    return acumulado;
}

int main() {

    long long n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        long valor1, valor2;
        std::cin >> valor1 >> valor2;

        long respuesta = suma_rest(valor1,valor2);

        std::cout << respuesta << std::endl;

    }

    return 0;
}

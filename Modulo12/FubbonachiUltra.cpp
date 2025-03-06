#include <iostream>
#include <array>
using namespace std;

constexpr long long MODULO = 999999937;

array<array<long long, 2>, 2> multiplicar_matrices(const array<array<long long, 2>, 2>& A, const array<array<long long, 2>, 2>& B) {
    array<array<long long, 2>, 2> resultado = {};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                resultado[i][j] = (resultado[i][j] + A[i][k] * B[k][j]) % MODULO;
            }
        }
    }
    return resultado;
}

array<array<long long, 2>, 2> elevar_matriz(array<array<long long, 2>, 2> base, long long exponente) {
    array<array<long long, 2>, 2> resultado = {{{1, 0}, {0, 1}}}; 
    while (exponente > 0) {
        if (exponente % 2 != 0) {
            resultado = multiplicar_matrices(resultado, base);
        }
        base = multiplicar_matrices(base, base);
        exponente /= 2;
    }
    return resultado;
}

long long obtener_fibonacci(long long n) {
    if (n == 0) return 0;
    array<array<long long, 2>, 2> matriz_fibonacci = {{{1, 1}, {1, 0}}};
    array<array<long long, 2>, 2> resultado = elevar_matriz(matriz_fibonacci, n - 1);
    return resultado[0][1];
}

int main() {
    int casos;
    cin >> casos;
    
    while (casos--) {
        long long n;
        cin >> n;
        cout << obtener_fibonacci(n) << "\n";
    }
    
    return 0;
}
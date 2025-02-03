#include <iostream>
#include <vector>
using namespace std;

const int MOD = 999999937;
const int maxR = 500;

// Función para calcular a^b % MOD (exponenciación rápida)
long long modExp(long long a, long long b, long long mod) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

int main() {
    vector<long long> fact(maxR + 1, 1); 
    vector<long long> invFact(maxR + 1, 1); 
    for (int i = 2; i <= maxR; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    for (int i = 1; i <= maxR; i++) {
        invFact[i] = modExp(fact[i], MOD - 2, MOD);
    }

    vector<long long> maximos(maxR + 1, 0);
    for (int r = 0; r <= maxR; r++) {
        int n = (r % 2 == 0) ? r / 2 : r / 2 + 1; 
        maximos[r] = (fact[r] * invFact[n] % MOD) * invFact[r - n] % MOD;
    }

    int casos;
    cin >> casos;
    while (casos--) {
        int fila;
        cin >> fila;
        cout << maximos[fila-1] << endl;
    }

    return 0;
}

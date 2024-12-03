#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector<int> cribar(int n){
    vector<int> primos;
    vector<bool> es_compuesto(n);

    for (int i = 2; i<n; i++){
        if (!es_compuesto[i]) {primos.push_back(i);}

        for (int j = 0; i*primos[j]<n && j <primos.size();j++){
            es_compuesto[i* primos[j]] = true;
            if (i % primos[j] == 0 )break;
        }
    }

    return primos;
}

int buscar_primo(const vector<int>& primos, long long numero){
    int respuesta = 0;
    for (int primo:primos){
        if (primo> numero){
            break;
        }
        respuesta++;
    }
    return respuesta;
}



int main(){
    vector<int> primos = cribar(100000);

    int entrada;

    cin>> entrada;
for (int i = 0; i < entrada; i++) {
        long long caso;
        cin >> caso;

        if (caso <= 1) {
            cout << "0" << endl;
            continue;
        }

        cout << buscar_primo(primos,caso) - round( caso/log(caso)) << endl;
    }

    return 0;
}


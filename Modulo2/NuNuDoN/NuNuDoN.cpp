#include <iostream>
#include <cmath> 
#include <vector>

using namespace std;

long long num_divisores(long long n){

    if (n == 1){return 1;}

    long divisores = 2;
    for (long long j = 2; j <= sqrt(n); ++j) {

        if (n % j == 0) {

            if (j != n / j) {
                divisores+=2;
            } else {
                divisores++;
            }
        }
    }

    return divisores;
}

vector<int> nuNuDoN(){

    vector<int> nuDoN = {1};
    int n;

    while (nuDoN.back()<=100000){
        n = nuDoN.back() + num_divisores(nuDoN.back());
        nuDoN.push_back(n);
    }

    return nuDoN;
}

int buscar(const vector<int>& nuNuDoN, long long numero, long long limite){

    auto it = lower_bound(nuNuDoN.begin(), nuNuDoN.end(),numero);
    int contador = 0;

    while(*it<=limite){
        contador++;
        ++it;
    }

    return contador;
}


int main() {

    int contador;   
    long long entrada;

    vector<int> secuencia = nuNuDoN();

    cin >> contador;  

    for (int i = 0; i < contador; ++i) {
        int a,b;
        cin >> a >> b;  
        cout << buscar(secuencia,a,b) << endl; 

        
    }

    return 0;
}

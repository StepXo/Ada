#include <iostream>

using namespace std;

int contar_divisores(int n) {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            count++;
        }
    }
    return count;
}

int main () {
    int casos;
    cin>> casos;
    while (casos--){
        int numero;
        cin>>numero;
        int respuesta = contar_divisores(numero);
        cout<<respuesta<<endl;
    }
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int C; 
    cin >> C;

    while (C--) {
        int N; 
        cin >> N;

        vector<long long> tapas(N);

        for (long i = 0; i < N; i++) {
            cin >> tapas[i];
        }
        sort(tapas.begin(), tapas.end());


        long long bebidas = 0;
        long i = 0, j = N - 1;

        while (i < j) {
            if (tapas[i] + tapas[j] >= 1000) {
                bebidas++; 
                i++; 
                j--;
            } else {
                i++;
            }
        }

        cout << bebidas << endl;
    }

    return 0;
}

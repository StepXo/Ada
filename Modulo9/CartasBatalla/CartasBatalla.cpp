#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

unordered_map<int, int> memo_divisores;

int contar_divisores(int n) {
    if (memo_divisores.find(n) != memo_divisores.end()) {
        return memo_divisores[n];
    }
    int count = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            count++;
            if (i != n / i) count++;
        }
    }
    memo_divisores[n] = count;
    return count;
}

int fusionar_cartas(vector<pair<int, int>>& cartas) {
    int N = cartas.size();
    sort(cartas.begin(), cartas.end());
    
    vector<vector<int>> sum(N, vector<int>(N, 0));
    
    for (int i = 0; i < N; ++i) {
        sum[i][i] = cartas[i].second;
    }
    
    for (int len = 2; len <= N; ++len) {
        for (int i = 0; i <= N - len; ++i) {
            int j = i + len - 1;
            sum[i][j] = 0; 

            for (int k = i; k < j; ++k) {
                int suma_poder = sum[i][k] + sum[k + 1][j];
                suma_poder += contar_divisores(suma_poder);
                
                sum[i][j] = max(sum[i][j], suma_poder);
            }
        }
    }
    
    return sum[0][N - 1];
}

int main() {
    int C;
    cin >> C;
    vector<int> resultados;
    
    while (C--) {
        int N;
        cin >> N;
        vector<pair<int, int>> cartas(N);
        
        for (int i = 0; i < N; ++i) {
            cin >> cartas[i].first >> cartas[i].second;
        }
        
        resultados.push_back(fusionar_cartas(cartas));
    }
    
    for (int resultado : resultados) {
        cout << resultado << "\n";
    }
    
    return 0;
}

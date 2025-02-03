#include <iostream>
#include <vector>

using namespace std;

int main() {
    int P; 
    cin >> P;

    vector<pair<int, int>> productos(P); 
    for (int i = 0; i < P; i++) {
        cin >> productos[i].first >> productos[i].second;
    }

    int J; 
    cin >> J;

    vector<int> capacidades(J); 
    for (int i = 0; i < J; i++) {
        cin >> capacidades[i];
    }

    int totalMaximo = 0;
    for (int k = 0; k < J; k++) {
        int capacidad = capacidades[k]; 
        vector<int> dp(capacidad + 1, 0); 
        for (const auto& producto : productos) {
            int costo = producto.first; 
            int peso = producto.second;

            for (int w = capacidad; w >= peso; w--) {
                dp[w] = max(dp[w], dp[w - peso] + costo);
            }
        }

        totalMaximo += dp[capacidad];
    }

    cout << totalMaximo << endl;

    return 0;
}

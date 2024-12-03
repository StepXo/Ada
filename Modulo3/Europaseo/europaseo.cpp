#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

void entry_processing(vector<long long>& fila, int tamaño) {
    string line;
    getline(cin, line);
    istringstream stream(line);
    for (int i = 0; i < tamaño; i++) {
        string value;
        stream >> value;
        if (value == "n.a") {
            fila.push_back(-1); 
        } else {
            fila.push_back(stoll(value)); 
        }
    }
}

bool validate(vector<int>& perm, vector<vector<long long>>& matriz) {
    for (size_t i = 0; i < perm.size() - 1; i++) {
        int from = perm[i];
        int to = perm[i + 1];

        if (matriz[from][to] == -1) {
            return false;
        }
    }
    return true;
}

int main() {
    int entrada;
    cin >> entrada;
    cin.ignore();

    for (int i = 0; i < entrada; i++) {
        int tamaño;
        cin >> tamaño;
        cin.ignore();

        vector<vector<long long>> matriz(tamaño, vector<long long>());
        double contador = LLONG_MAX; 

        for (int j = 0; j < tamaño; j++) {
            entry_processing(matriz[j], tamaño);
        }

        vector<int> nums(tamaño);
        for (int j = 0; j < tamaño; j++) {
            nums[j] = j;
        }

        bool valido = false;

        do {
            double suma = 0;
            if (!validate(nums, matriz)) {
                continue;
            }
            valido = true;
            for (int i = 0;i<tamaño-1;i++){
                suma += matriz[nums[i]][nums[i+1]];
            }
            if (suma < contador) {
                contador = suma; 
            }
        } while (next_permutation(nums.begin(), nums.end()));

        if (valido) {
            cout << round(contador / 10.0) << endl;
        } else {
            cout << "imposible" << endl;
        }
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

bool bfs(int n, vector<vector<int>>& capacidad, vector<vector<int>>& flujo, int origen, int destino, vector<int>& parent) {
    // Vector para marcar los nodos visitados
    vector<bool> visitado(n, false);
    queue<int> q;
    
    q.push(origen);
    visitado[origen] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v = 0; v < n; ++v) {
            if (!visitado[v] && capacidad[u][v] > flujo[u][v]) {
                q.push(v);
                visitado[v] = true;
                parent[v] = u;
                if (v == destino) return true;
            }
        }
    }
    
    return false;
}

int edmondsKarp(int n, vector<vector<int>>& capacidad, int origen, int destino) {
    vector<vector<int>> flujo(n, vector<int>(n, 0));
    int flujoMaximo = 0;
    
    vector<int> parent(n, -1);
    
    while (bfs(n, capacidad, flujo, origen, destino, parent)) {
        int flujoAumentante = INT_MAX;
        
        for (int v = destino; v != origen; v = parent[v]) {
            int u = parent[v];
            flujoAumentante = min(flujoAumentante, capacidad[u][v] - flujo[u][v]);
        }
        
        for (int v = destino; v != origen; v = parent[v]) {
            int u = parent[v];
            flujo[u][v] += flujoAumentante; 
            flujo[v][u] -= flujoAumentante; 
        }
        
        flujoMaximo += flujoAumentante; 
    }
    
    return flujoMaximo;
}

int main() {
    int n = 6;
    vector<vector<int>> capacidad(n, vector<int>(n, 0));
    
    capacidad[0][1] = 16;
    capacidad[0][2] = 13;
    capacidad[1][2] = 10;
    capacidad[1][3] = 12;
    capacidad[2][1] = 4;
    capacidad[2][4] = 14;
    capacidad[3][2] = 9;
    capacidad[3][5] = 20;
    capacidad[4][3] = 7;
    capacidad[4][5] = 4;
    
    int origen = 0;
    int destino = 5;
    
    int flujoMaximo = edmondsKarp(n, capacidad, origen, destino);
    
    cout << "El flujo máximo es: " << flujoMaximo << endl;
    
    return 0;
}

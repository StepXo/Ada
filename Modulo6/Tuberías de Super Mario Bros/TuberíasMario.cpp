#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

bool bfs(int n, vector<vector<int>>& capacidad, vector<vector<int>>& flujo, int origen, int destino, vector<int>& parent) {
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
    int C;
    cin>>C;
    while (C--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> capacidad(n, vector<int>(n, 0));

        while (m--) {
            int u, v, cap;
            cin >> u >> v >> cap;
            capacidad[u][v] = cap;
        }
        
        int flujoMaximo = edmondsKarp(n, capacidad, 0, n - 1);
        cout << flujoMaximo << endl;
    }
    return 0;
}

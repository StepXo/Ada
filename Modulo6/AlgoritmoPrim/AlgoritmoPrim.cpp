#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; 

void prim(int n, vector<vector<pii>>& grafo) {
    vector<int> dist(n, INT_MAX);
    dist[0] = 0; 

    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, 0});

    vector<bool> enMST(n, false);
    int costoTotal = 0;

    while (!pq.empty()) {
        int u = pq.top().second;  
        int pesoU = pq.top().first;
        pq.pop();

        if (enMST[u]) continue;

        enMST[u] = true;
        costoTotal += pesoU;

        for (const auto& vecino : grafo[u]) {
            int v = vecino.first; 
            int peso = vecino.second;  

            if (!enMST[v] && peso < dist[v]) {
                dist[v] = peso;
                pq.push({peso, v});
            }
        }
    }

    cout << "Costo total del MST: " << costoTotal << endl;
}

int main() {
    int n = 5; 
    vector<vector<pii>> grafo(n);

    grafo[0].push_back({1, 1});
    grafo[0].push_back({2, 2});
    grafo[1].push_back({2, 3});
    grafo[1].push_back({3, 4});
    grafo[2].push_back({3, 5});

    prim(n, grafo);

    return 0;
}

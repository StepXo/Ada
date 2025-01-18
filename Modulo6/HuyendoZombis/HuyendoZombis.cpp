#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int destino;
    int peso;
};

vector<int> dijkstra(int n, int origen, const vector<vector<Edge>>& grafo) {
    vector<int> distancias(n, INT_MAX);
    distancias[origen] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, origen});

    while (!pq.empty()) {
        auto [distActual, nodo] = pq.top();
        pq.pop();

        if (distActual > distancias[nodo]) continue;

        for (const auto& arista : grafo[nodo]) {
            int nuevoPeso = distActual + arista.peso;
            if (nuevoPeso < distancias[arista.destino]) {
                distancias[arista.destino] = nuevoPeso;
                pq.push({nuevoPeso, arista.destino});
            }
        }
    }

    return distancias;
}

int main() {
    int N, M, P;
    cin >> N >> M >> P;

    vector<vector<Edge>> grafo(N + 1);

    for (int i = 0; i < M; ++i) {
        int u, v, D;
        cin >> u >> v >> D;
        grafo[u].push_back({v, D});
        grafo[v].push_back({u, D});
    }

    vector<int> destinos(P);
    for (int& destino : destinos) {
        cin >> destino;
    }

    vector<int> distancias = dijkstra(N + 1, 0, grafo);

    for (const int& destino : destinos) {
        if (destino >= distancias.size() || distancias[destino] == INT_MAX) {
            cout << "ZOMBI\n";
        } else {
            cout << distancias[destino] << "\n";
        }
    }

    return 0;
}

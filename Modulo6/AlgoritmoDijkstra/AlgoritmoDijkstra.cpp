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
    int n = 5; 
    int origen = 0; 

    vector<vector<Edge>> grafo(n);

    grafo[0].push_back({1, 2});
    grafo[0].push_back({2, 4});
    grafo[1].push_back({2, 1});
    grafo[1].push_back({3, 7});
    grafo[2].push_back({3, 3});
    grafo[3].push_back({4, 1});
    grafo[4].push_back({0, 8});

    vector<int> distancias = dijkstra(n, origen, grafo);

    cout << "Distancias desde el nodo " << origen << ":\n";
    for (int i = 0; i < distancias.size(); ++i) {
        cout << "Nodo " << i << ": " << (distancias[i] == INT_MAX ? -1 : distancias[i]) << "\n";
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Nodo {
    int ciudad;
    int costo;
    bool operator>(const Nodo& otro) const {
        return costo > otro.costo;
    }
};

int main() {
    int casos;
    cin >> casos;

    while (casos--) {
        int N, M, A;
        cin >> N >> M >> A;

        vector<vector<pair<int, int>>> grafo(N);
        for (int i = 0; i < M; ++i) {
            int u, v, costo;
            cin >> u >> v >> costo;
            u--;
            v--;
            grafo[u].emplace_back(v, costo);
            grafo[v].emplace_back(u, costo);
        }

        vector<bool> visitado(N, false);
        priority_queue<Nodo, vector<Nodo>, greater<>> pq;

        long long mstCosto = 0;
        int componentes = 0;
        int aeropuertos = 0;

        for (int inicio = 0; inicio < N; ++inicio) {
            if (!visitado[inicio]) {
                componentes++;
                aeropuertos++;
                pq.push({inicio, 0});

                while (!pq.empty()) {
                    Nodo actual = pq.top();
                    pq.pop();

                    if (visitado[actual.ciudad]) continue;
                    visitado[actual.ciudad] = true;

                    mstCosto += actual.costo;

                    for (const auto& vecino : grafo[actual.ciudad]) {
                        int destino = vecino.first;
                        int costo = vecino.second;

                        if (!visitado[destino] && costo < A) {
                            pq.push({destino, costo});
                        }
                    }
                }
            }
        }

        long long costoTotal = mstCosto + static_cast<long long>(aeropuertos) * A;
        cout << costoTotal << " " << aeropuertos << "\n";
    }

    return 0;
}

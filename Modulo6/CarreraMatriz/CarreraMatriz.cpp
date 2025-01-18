#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>

using namespace std;

typedef pair<int, pair<int, int>> Node; // (costo acumulado, fila, columna)

vector<int> minimo_costo_para_salir(int t, vector<vector<vector<int>>> &casos) {
    vector<int> resultados;

    for (int caso_idx = 0; caso_idx < t; ++caso_idx) {
        int n = casos[caso_idx].size();
        int m = casos[caso_idx][0].size();
        auto &matriz = casos[caso_idx];

        vector<vector<int>> costo_min(n, vector<int>(m, numeric_limits<int>::max()));
        costo_min[0][0] = 0;

        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.push({0, {0, 0}});

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        while (!pq.empty()) {
            auto [costo_actual, pos] = pq.top();
            auto [x, y] = pos;
            pq.pop();

            if (x == n - 1 && y == m - 1) {
                resultados.push_back(costo_actual);
                break;
            }

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int nuevo_costo = costo_actual + matriz[nx][ny];
                    if (nuevo_costo < costo_min[nx][ny]) {
                        costo_min[nx][ny] = nuevo_costo;
                        pq.push({nuevo_costo, {nx, ny}});
                    }
                }
            }
        }
    }

    return resultados;
}

int main() {
    int t;
    cin >> t;

    vector<vector<vector<int>>> casos(t);

    for (int caso_idx = 0; caso_idx < t; ++caso_idx) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> matriz(n, vector<int>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> matriz[i][j];
            }
        }

        casos[caso_idx] = matriz;
    }

    vector<int> resultados = minimo_costo_para_salir(t, casos);

    for (int res : resultados) {
        cout << res << endl;
    }

    return 0;
}

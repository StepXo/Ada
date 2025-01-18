#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <limits>

using namespace std;

double distancia(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double prim(int N, const vector<pair<double, double>>& puntos) {
    vector<bool> visitado(N, false);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;

    pq.push({0.0, 0});
    double mstPeso = 0.0;

    while (!pq.empty()) {
        auto [peso, nodo] = pq.top();
        pq.pop();

        if (visitado[nodo]) continue;
        visitado[nodo] = true;
        mstPeso += peso;

        for (int i = 0; i < N; ++i) {
            if (!visitado[i]) {
                double d = distancia(puntos[nodo].first, puntos[nodo].second, puntos[i].first, puntos[i].second);
                pq.push({d, i});
            }
        }
    }

    return mstPeso;
}

int main() {
    int casos;
    cin >> casos;

    while (casos--) {
        int N;
        cin >> N;

        vector<pair<double, double>> puntos(N);
        for (int i = 0; i < N; ++i) {
            cin >> puntos[i].first >> puntos[i].second;
        }

        double mstPeso = prim(N, puntos);
        printf("%.1f\n", mstPeso);
    }

    return 0;
}

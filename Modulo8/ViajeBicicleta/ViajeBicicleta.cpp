#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    while (true) {
        int N;
        cin >> N;

        if (N == 0) break;

        vector<vector<int>> dist(N, vector<int>(N, INF)); 

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                string value;
                cin >> value;

                if (i == j) {
                    dist[i][j] = 0; 
                } else if (value == "-") {
                    dist[i][j] = INF;
                } else {
                    dist[i][j] = stoi(value);
                }
            }
        }

        //Floyd-Warshall
        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Enconrtar
        int maxDistance = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][j] != INF) {
                    maxDistance = max(maxDistance, dist[i][j]);
                }
            }
        }

        cout << maxDistance << endl;
    }

    return 0;
}

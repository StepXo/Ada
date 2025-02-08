#include <iostream>
#include <vector>
#include <limits.h>
#include <sstream>

using namespace std;

vector<vector<int>> matrix_chain_multiplication(const vector<int>& p, vector<vector<int>>& M) {
    int N = p.size() - 1;
    vector<vector<int>> S(N, vector<int>(N, 0));
    M.assign(N, vector<int>(N, 0));

    for (int len = 2; len <= N; ++len) {
        for (int i = 0; i <= N - len; ++i) {
            int j = i + len - 1;
            M[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = M[i][k] + M[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (cost < M[i][j]) {
                    M[i][j] = cost;
                    S[i][j] = k;
                }
            }
        }
    }

    return S;
}

void parenthesization(int i, int j, const vector<vector<int>>& S) {
    if (i == j) {
        cout << "M" << (i + 1);
    } else {
        cout << "(";
        parenthesization(i, S[i][j], S);
        cout << " x ";
        parenthesization(S[i][j] + 1, j, S);
        cout << ")";
    }
}

int main() {
    int C;
    cin >> C;
    cin.ignore(); 

    while (C--) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        vector<int> p;
        int value;

        while (ss >> value) {
            p.push_back(value);
        }

        vector<vector<int>> M;
        int N = p.size()-1;
        vector<vector<int>> S = matrix_chain_multiplication(p, M);

        parenthesization(0, N - 1, S);
        cout << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <limits.h>
#include <algorithm>

using namespace std;

struct Node {
    string serial;
    Node* left;
    Node* right;
    Node(string s) : serial(s), left(nullptr), right(nullptr) {}
};

Node* buildTree(const vector<vector<int>>& S, const vector<string>& serials, int i, int j) {
    if (i > j) return nullptr;
    int r = S[i][j];
    Node* node = new Node(serials[r]);
    node->left = buildTree(S, serials, i, r - 1);
    node->right = buildTree(S, serials, r + 1, j);
    return node;
}

void printTree(Node* root, int depth = 0) {
    if (!root) return;
    printTree(root->right, depth + 1);
    cout << string(depth, '\t') << root->serial << endl;
    printTree(root->left, depth + 1);
}

void optimalTree(vector<pair<string, int>>& bulbs, int caseNumber) {
    int N = bulbs.size();
    if (N == 0) {
        cout << "caso " << caseNumber << ":\n" << endl;
        return;
    }

    sort(bulbs.begin(), bulbs.end());

    vector<string> serials(N);
    vector<int> lumens(N);
    for (int i = 0; i < N; i++) {
        serials[i] = bulbs[i].first;
        lumens[i] = bulbs[i].second;
    }

    vector<vector<int>> C(N, vector<int>(N, 0));
    vector<vector<int>> S(N, vector<int>(N, 0));
    vector<int> prefixSum(N + 1, 0);

    for (int i = 0; i < N; i++) {
        prefixSum[i + 1] = prefixSum[i] + lumens[i];
    }

    for (int i = 0; i < N; i++) {
        C[i][i] = lumens[i];
        S[i][i] = i;
    }

    for (int nodes = 2; nodes <= N; nodes++) {
        for (int i = 0; i <= N - nodes; i++) {
            int j = i + nodes - 1;
            int minCost = INT_MAX, bestRoot = -1;

            for (int r = i; r <= j; r++) {
                int cost = (r > i ? C[i][r - 1] : 0) + (r < j ? C[r + 1][j] : 0);
                if (cost < minCost) {
                    minCost = cost;
                    bestRoot = r;
                }
            }
            C[i][j] = minCost + (prefixSum[j + 1] - prefixSum[i]);
            S[i][j] = bestRoot;
        }
    }

    Node* root = buildTree(S, serials, 0, N - 1);

    cout << "caso " << caseNumber << ":" << endl<<endl;
    printTree(root);
    cout << endl;

}

int main() {
    int C;
    cin >> C;
    cin.ignore(); // Limpiar buffer

    for (int caseNumber = 1; caseNumber <= C; caseNumber++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<pair<string, int>> bulbs;
        string token;

        while (ss >> token) {
            size_t pos = token.find(':');
            string serial = token.substr(0, pos);
            int lumens = stoi(token.substr(pos + 1));
            bulbs.emplace_back(serial, lumens);
        }

        optimalTree(bulbs, caseNumber);
    }

    return 0;
}

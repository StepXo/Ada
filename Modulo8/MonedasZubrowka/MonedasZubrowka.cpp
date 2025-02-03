#include <iostream>
#include <vector>
#include <sstream>
#include <climits>

using namespace std;

int calcMinBilletes(int M, vector<int> &denominations) {
    
    vector<int> dp(M + 1, INT_MAX);
    dp[0] = 0; 

    for (int denom : denominations) {
        for (int x = denom; x <= M; ++x) {
            if (dp[x - denom] != INT_MAX) {
                dp[x] = min(dp[x], dp[x - denom] + 1);
            }
        }
    }

    return dp[M];
}

int main() {
    int C;
    cin >> C;
    cin.ignore();

    for (int i = 0; i < C; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        int M;
        ss >> M;

        vector<int> denominations;
        int denom;
        while (ss >> denom) {
            denominations.push_back(denom);
        }

        int result = calcMinBilletes(M, denominations);
        cout << result << endl;
    }

    return 0;
}

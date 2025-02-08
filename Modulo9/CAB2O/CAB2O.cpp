#include <iostream>
#include <vector>
#include <limits>
#include <sstream>

using namespace std;

int optimal_bst_cost(const vector<int>& freqs) {
    int N = freqs.size();
    if (N == 0) return 0;
    
    vector<vector<int>> dp(N, vector<int>(N, 0));
    vector<int> prefix_sum(N + 1, 0);
    
    for (int i = 0; i < N; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + freqs[i];
    }
    
    for (int length = 1; length <= N; length++) {
        for (int i = 0; i + length - 1 < N; i++) {
            int j = i + length - 1;
            dp[i][j] = numeric_limits<int>::max();
            
            for (int r = i; r <= j; r++) {
                int cost_left = (r > i) ? dp[i][r - 1] : 0;
                int cost_right = (r < j) ? dp[r + 1][j] : 0;
                int total_cost = cost_left + cost_right + (prefix_sum[j + 1] - prefix_sum[i]);
                
                dp[i][j] = min(dp[i][j], total_cost);
            }
        }
    }
    
    return dp[0][N - 1];
}

int main() {
    int C;
    cin >> C;
    cin.ignore();
    
    vector<int> results;
    for (int i = 0; i < C; i++) {
        string line;
        getline(cin, line);
        
        istringstream iss(line);
        vector<int> freqs;
        int num;
        while (iss >> num) {
            freqs.push_back(num);
        }
        
        results.push_back(optimal_bst_cost(freqs));
    }
    
    for (int res : results) {
        cout << res << endl;
    }
    
    return 0;
}


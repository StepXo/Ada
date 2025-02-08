#include <iostream>
#include <vector>

using namespace std;

const int MODULO = 1000000007;

const int MOD = 1000000007;

int precompute(int max_n) {
    
    vector<int> dp(max_n + 1, 0), espacio(max_n + 1, 0);
    espacio[0] = 1;

    for (int i = 0; i <= max_n; i++) {
        if (espacio[i] > 0) {
            for (int digit = 1; digit <= 10; digit++) { 
                if (i + digit <= max_n) dp[i + digit] = (dp[i + digit] + espacio[i]) % MOD;
            }
        }
        if (dp[i] > 0) espacio[i + 1] = (espacio[i + 1] + dp[i]) % MOD;
    }

    return dp[max_n];
}


int main() {
    int C;
    cin >> C;
    int max_n;

    while (C--) {
        cin >> max_n;
        int dp = precompute(max_n);
        cout<<dp<<endl;
    }

    return 0;
}

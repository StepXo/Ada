#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int minOperationsToPalindrome(const string &str) {
    int n = str.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (str[i] == str[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i + 1][j], dp[i][j - 1], dp[i + 1][j - 1]});
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    int N;
    cin >> N;
    cin.ignore();

    while (N--) {
        string str;
        getline(cin, str);

        int result = minOperationsToPalindrome(str);
        cout << result << endl;
    }

    return 0;
}

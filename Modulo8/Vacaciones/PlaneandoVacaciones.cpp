#include <iostream>
#include <vector>
#include <string>

using namespace std;

int longestCommonSubsequence(const string &sugestion1, const string &sugestion2) {
    int TamañoN = sugestion1.size();
    int TamañoM = sugestion2.size();

    vector<vector<int>> dp(TamañoN + 1, vector<int>(TamañoM + 1, 0));

    for (int i = 1; i <= TamañoN; ++i) {
        for (int j = 1; j <= TamañoM; ++j) {
            if (sugestion1[i - 1] == sugestion2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[TamañoN][TamañoM];
}

int main() {
    int S;
    cin >> S;
    cin.ignore(); 

    for (int i = 0; i < S; ++i) {
        string sugestion1, sugestion2;
        cin >> sugestion1 >> sugestion2;

        int result = longestCommonSubsequence(sugestion1, sugestion2);
        cout << result << endl;
    }

    return 0;
}

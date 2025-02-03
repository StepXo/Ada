#include <iostream>
#include <vector>
#include <numeric>
#include <sstream>

using namespace std;

int minimum_difference_case(const vector<int>& coins) {
    int total = accumulate(coins.begin(), coins.end(), 0);
    int target = total / 2;

    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int coin : coins) {
        for (int j = target; j >= coin; --j) {
            dp[j] = dp[j] || dp[j - coin];
        }
    }

    int closest_sum = 0;
    for (int i = target; i >= 0; --i) {
        if (dp[i]) {
            closest_sum = i;
            break;
        }
    }

    int other_sum = total - closest_sum;
    return abs(closest_sum - other_sum);
}

int main() {
    int C;
    cin >> C;
    cin.ignore();

    for (int i = 0; i < C; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> coins;
        int coin;
        while (ss >> coin) {
            coins.push_back(coin);
        }

        cout << minimum_difference_case(coins) << endl;
    }

    return 0;
}

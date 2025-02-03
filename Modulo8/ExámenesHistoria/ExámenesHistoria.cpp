#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int calculateLCS(const vector<int> &perfect, const vector<int> &student) {
    int n = perfect.size();
    int m = student.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (perfect[i - 1] == student[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main() {
    int numCases;
    cin >> numCases;
    cin.ignore();

    for (int caseIndex = 1; caseIndex <= numCases; ++caseIndex) {
        if (caseIndex > 1) cout << endl;
        cout << "caso " << caseIndex << ":" << endl;

        int numExams;
        cin >> numExams;
        cin.ignore();

        string line;
        getline(cin, line);
        stringstream ssPerfect(line);

        vector<int> perfectOrder;
        int value;

        while (ssPerfect >> value) {
            perfectOrder.push_back(value);
        }

        for (int i = 0; i < numExams; ++i) {
            getline(cin, line);
            stringstream ssStudent(line);
            vector<int> studentOrder;
            while (ssStudent >> value) {
                studentOrder.push_back(value);
            }

            int lcsLength = calculateLCS(perfectOrder, studentOrder);
            int score = round((lcsLength * 100.0) / perfectOrder.size());

            cout << score << endl;
        }
    }

    return 0;
}

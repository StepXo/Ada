#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string pad_left(const string &num, int len) {
    if (num.size() >= len) return num;
    return string(len - num.size(), '0') + num;
}

string multiply_strings(const string &num1, const string &num2) {
    int len1 = num1.size(), len2 = num2.size();
    vector<int> result(len1 + len2, 0);

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    string result_str;
    for (int num : result) {
        if (!(result_str.empty() && num == 0)) {
            result_str.push_back(num + '0');
        }
    }
    return result_str.empty() ? "0" : result_str;
}

string add_strings(const string &num1, const string &num2) {
    string result;
    int carry = 0, i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += (num1[i--] - '0');
        if (j >= 0) sum += (num2[j--] - '0');

        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

string four_subproducts(string X, string Y, int N) {
    X = pad_left(X, N);
    Y = pad_left(Y, N);

    if (N == 1) {
        string result = multiply_strings(X, Y);
        cout << result << "\n";  
        return result;
    }

    int half_N = N / 2;
    string a = X.substr(0, X.size() - half_N);
    string b = X.substr(X.size() - half_N);
    string c = Y.substr(0, Y.size() - half_N);
    string d = Y.substr(Y.size() - half_N);

    string P1 = four_subproducts(a, c, half_N);
    string P2 = four_subproducts(a, d, half_N);
    string P3 = four_subproducts(b, c, half_N);
    string P4 = four_subproducts(b, d, half_N);

    string P1_shifted = (P1 == "0") ? "0" : P1 + string(N, '0');
    string P2_P3_shifted = (add_strings(P2, P3) == "0") ? "0" : add_strings(P2, P3) + string(half_N, '0');

    string result = add_strings(add_strings(P1_shifted, P2_P3_shifted), P4);
    cout << result << "\n";  
    return result;
}

void karatsuba(const vector<tuple<int, string, string>>& test_cases) {
    for (size_t i = 0; i < test_cases.size(); i++) {
        cout << "caso " << i + 1 << ":\n";

        int N;
        string X, Y;
        tie(N, X, Y) = test_cases[i];

        string final_result = four_subproducts(X, Y, N);

        if (i != test_cases.size() - 1) {
            cout << "\n";
        }
    }
}

int main() {
    int C;
    cin >> C;

    vector<tuple<int, string, string>> test_cases;
    for (int i = 0; i < C; i++) {
        int N;
        string X, Y;
        cin >> N >> X >> Y;
        test_cases.emplace_back(N, X, Y);
    }

    karatsuba(test_cases);

    return 0;
}

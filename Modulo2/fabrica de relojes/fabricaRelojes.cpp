#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>

using namespace std;

void entry_processing(vector<long long>& numeros) {
    string line;
    getline(cin, line);
    istringstream stream(line);

    long long num;
    while (stream >> num) {
        numeros.push_back(num);
    }
}

long long mcd_multiple(const vector<long long>& nums) {
    if (nums.empty()) return 0;

    long long result = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) { // O(n) 
        result = gcd(result, nums[i]); // O(log(min(a, b)))
        if (result == 1) break;
    }

    return result;
}

int main() {
    int casos;
    cin >> casos;
    cin.ignore();

    for (int i = 0; i < casos; i++) {
        vector<long long> numeros = {};
        entry_processing(numeros);

        long long mcd = mcd_multiple(numeros);
        long long result = 0;
        for (long long numero:numeros){
            result += numero/mcd;
        }
        cout << result << endl;
    }

    return 0;
}

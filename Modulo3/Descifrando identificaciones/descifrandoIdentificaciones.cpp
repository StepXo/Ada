#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <unordered_map>

using namespace std;

unordered_map<char, int> letra_a_residuo = {
    {'T', 0}, {'R', 1}, {'W', 2}, {'A', 3}, {'G', 4}, {'M', 5},
    {'Y', 6}, {'F', 7}, {'P', 8}, {'D', 9}, {'X', 10}, {'B', 11},
    {'N', 12}, {'J', 13}, {'Z', 14}, {'S', 15}, {'Q', 16}, {'V', 17},
    {'H', 18}, {'L', 19}, {'C', 20}, {'K', 21}, {'E', 22}
};

void entry_processing(string& line, vector<char>& numeros, char& resto, int& perm) {
    for (char c : line) {
        if (isdigit(c)) {
            numeros.push_back(c);
            continue;
        }

        if (c == '?') {
            numeros.push_back(c);
            perm++;
            continue;
        }

        resto = c;
    }
}

bool next_combination(vector<int>& combination, int perm) {
    for (int i = perm - 1; i >= 0; i--) {
        if (combination[i] < 9) {
            combination[i]++;
            return true;
        } else {
            combination[i] = 0;
        }
    }
    return false; 
}


bool validate(vector<char>& nums, int rest, vector<int> combination) {
    string number_str;
    int combination_index = 0;

    for (char c : nums) {
        if (c == '?') {
            number_str += to_string(combination[combination_index]);
            combination_index++;
        } else {
            number_str += c;
        }
    }

    long long number = stoll(number_str) % 23;

    return number == rest;
}

int main() {
    int entrada;
    cin >> entrada;
    cin.ignore();

    for (int i = 0; i < entrada; i++) {
        string line;
        getline(cin, line);

        vector<char> nums;
        char resto = '\0'; 
        int perm = 0;

        entry_processing(line, nums, resto, perm);

        vector<int> combination(perm, 0);
        long long contador = 0;

        int residuo = letra_a_residuo[resto];

        do {
            if (validate(nums, residuo, combination)) {
                contador++;
            }
        } while (next_combination(combination, perm));

        cout << contador << endl;
    }

    return 0;
}


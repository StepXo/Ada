#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> merge(const vector<int>& XL, const vector<int>& XR) {
    int i = 0, j = 0, k = 0;
    int M = XL.size() + XR.size();
    vector<int> Z(M);
    
    while (k < M) {
        if (i < XL.size() && (j >= XR.size() || XL[i] <= XR[j])) {
            Z[k] = XL[i];
            i++;
        } else {
            Z[k] = XR[j];
            j++;
        }
        k++;
    }
    return Z;
}

vector<int> mergeSort(vector<int>& X, int M, vector<string>& result) {
    if (M > 1) {
        int mid = M / 2;
        vector<int> XL(X.begin(), X.begin() + mid);
        vector<int> XR(X.begin() + mid, X.end());
        
        vector<int> sortedXL = mergeSort(XL, mid, result);
        vector<int> sortedXR = mergeSort(XR, M - mid, result);
        
        vector<int> merged = merge(sortedXL, sortedXR);
        
        string mergedStr;
        for (int num : merged) {
            mergedStr += to_string(num);
        }
        result.push_back(mergedStr);
        
        return merged;
    } else {
        result.push_back(to_string(X[0]));
        return X;
    }
}

void processCases(int C) {
    cin.ignore();
    for (int i = 1; i <= C; ++i) {
        string line;
        getline(cin, line);
        
        vector<int> numbers;
        size_t pos = 0;
        while ((pos = line.find(" ")) != string::npos) {
            numbers.push_back(stoi(line.substr(0, pos)));
            line.erase(0, pos + 1);
        }
        numbers.push_back(stoi(line));
        
        vector<string> result;
        mergeSort(numbers, numbers.size(), result);
        
        cout << "caso " << i << ":\n";
        for (const string& s : result) {
            cout << s << "\n";
        }
        if (i != C) {
            cout << "\n";
        }
    }
}

int main() {
    int C;
    cin >> C;
    processCases(C);
    return 0;
}

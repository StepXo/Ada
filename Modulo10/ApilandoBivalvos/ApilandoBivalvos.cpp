#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> merged;
    size_t i = 0, j = 0;
    
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            merged.push_back(left[i++]);
        } else {
            merged.push_back(right[j++]);
        }
    }
    while (i < left.size()) merged.push_back(left[i++]);
    while (j < right.size()) merged.push_back(right[j++]);
    
    return merged;
}

int mergeSortCount(vector<int>& shells, int left, int right) {
    if (left == right) return 1; 
    
    int mid = (left + right) / 2;
    int left_towers = mergeSortCount(shells, left, mid);
    int right_towers = mergeSortCount(shells, mid + 1, right);
    
    vector<int> merged = merge(vector<int>(shells.begin() + left, shells.begin() + mid + 1),
                               vector<int>(shells.begin() + mid + 1, shells.begin() + right + 1));
    
    int total_towers = 1;
    for (size_t i = 1; i < merged.size(); i++) {
        if (merged[i] > merged[i - 1]) {
            total_towers++;
        }
    }
    
    return min(left_towers + right_towers, total_towers);
}

void processCase(vector<int>& shells) {
    cout << mergeSortCount(shells, 0, shells.size() - 1) << "\n";
}

int main() {
    int C;
    cin >> C;
    cin.ignore();
    
    while (C--) {
        vector<int> shells;
        string line;
        getline(cin, line);
        
        int value;
        size_t pos = 0;
        while ((pos = line.find(" ")) != string::npos) {
            shells.push_back(stoi(line.substr(0, pos)));
            line.erase(0, pos + 1);
        }
        shells.push_back(stoi(line));
        
        processCase(shells);
    }
    return 0;
}

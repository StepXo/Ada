#include <iostream>
#include <vector>

using namespace std;

long long mergeAndCount(vector<int>& arr, vector<int>& left, vector<int>& right) {
    int i = 0, j = 0, k = 0;
    long long inv_count = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            inv_count += left.size() - i;
        }
    }
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
    return inv_count;
}

long long countInversions(vector<int>& arr) {
    if (arr.size() <= 1) return 0;
    
    int mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
    
    long long inv_count = countInversions(left) + countInversions(right);
    inv_count += mergeAndCount(arr, left, right);
    
    return inv_count;
}

void processGame(vector<int>& cards) {
    long long inversions = countInversions(cards);
    if (inversions == 0) {
        cout << "Empate\n";
    } else if (inversions % 2 == 1) {
        cout << "Susana\n";
    } else {
        cout << "Pedro\n";
    }
}

int main() {
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;
        
        vector<int> cards(N);
        for (int i = 0; i < N; i++) {
            cin >> cards[i];
        }
        
        processGame(cards);
    }
    return 0;
}

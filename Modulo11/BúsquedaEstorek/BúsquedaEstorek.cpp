#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i], arr[low]);
    return i;
}

void findStatistic(vector<int>& arr, int low, int high, int k, vector<int>& pivot_indices) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);
        pivot_indices.push_back(pivotIndex + 1); 
        if (pivotIndex == k) {
            return;
        } else if (pivotIndex < k) {
            findStatistic(arr, pivotIndex + 1, high, k, pivot_indices);
        } else {
            findStatistic(arr, low, pivotIndex - 1, k, pivot_indices);
        }
    }
}

int main() {
    int k;
    while (cin >> k && k != 0) {
        cin.ignore();
        string line;
        getline(cin, line);
        
        vector<int> arr;
        stringstream ss(line);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        
        vector<int> pivot_indices;
        findStatistic(arr, 0, arr.size() - 1, k - 1, pivot_indices);
        
        for (size_t i = 0; i < pivot_indices.size(); i++) {
            if (i > 0) cout << " ";
            cout << pivot_indices[i];
        }
        cout << "\n";
    }
    return 0;
}

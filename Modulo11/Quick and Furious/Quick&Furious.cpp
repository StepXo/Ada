#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int recursive_calls;

int medianOfThree(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < arr[low]) swap(arr[mid], arr[low]);
    if (arr[high] < arr[low]) swap(arr[high], arr[low]);
    if (arr[mid] < arr[high]) swap(arr[mid], arr[high]);
    return high;
}

int partition(vector<int>& arr, int low, int high) {
    int pivotIndex = medianOfThree(arr, low, high);
    swap(arr[pivotIndex], arr[low]);
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

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        recursive_calls++;
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void processCase(vector<int>& arr) {
    recursive_calls = 0;
    quickSort(arr, 0, arr.size() - 1);
    cout << recursive_calls << "\n";
}

int main() {
    int C;
    cin >> C;
    cin.ignore();
    
    while (C--) {
        vector<int> arr;
        string line;
        getline(cin, line);
        
        int value;
        size_t pos = 0;
        while ((pos = line.find(" ")) != string::npos) {
            arr.push_back(stoi(line.substr(0, pos)));
            line.erase(0, pos + 1);
        }
        arr.push_back(stoi(line));
        
        processCase(arr);
    }
    return 0;
}

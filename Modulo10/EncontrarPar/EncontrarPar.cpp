#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long countPairs(const vector<int>& arr, int p) {
    long long count = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > p) break;
        count += arr.size();
    }
    return count;
}

pair<int, int> findKthPair(const vector<int>& arr, long long k) {
    int N = arr.size();
    
    int left = arr[0], right = arr[N - 1];
    int p;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long count = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] > mid) break;
            count += N;
        }
        if (count >= k) {
            p = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    int q;
    long long pos = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] > p) break;
        for (int j = 0; j < N; j++) {
            pos++;
            if (pos == k) {
                return {arr[i], arr[j]};
            }
        }
    }
    return {-1, -1};
}

int main() {
    int N;
    long long k;
    cin >> N >> k;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    pair<int, int> result = findKthPair(arr, k);

    cout << result.first << " " << result.second << endl;
    return 0;
}

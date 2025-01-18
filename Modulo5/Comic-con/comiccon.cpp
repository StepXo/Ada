#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    while (true) {
        int n;
        cin >> n;

        if (n == 0) {
            break;
        }

        vector<pair<int, int>> events;

        for (int i = 0; i < n; ++i) {
            int start, end;
            cin >> start >> end;
            events.emplace_back(start, 1);  
            events.emplace_back(end, -1); 
        }

        sort(events.begin(), events.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        long long max_overlap = 0;
        long long current_overlap = 0;

        for (const auto& event : events) {
            current_overlap += event.second;
            max_overlap = max(max_overlap, current_overlap);
        }

        if (max_overlap > 0) {
            max_overlap--;
        }
        cout << max_overlap << "\n";
    }

    return 0;
}

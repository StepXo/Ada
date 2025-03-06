#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int chebyshev_distance(pair<int, int> p1, pair<int, int> p2) {
    return max(abs(p1.first - p2.first), abs(p1.second - p2.second));
}

int brute_force(const vector<pair<int, int>>& points) {
    int n = points.size();
    if (n <= 1) return INT_MAX;

    int min_dist = INT_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int dist = chebyshev_distance(points[i], points[j]);
            min_dist = min(min_dist, dist);
        }
    }
    return min_dist;
}

int closest_pair_rec(const vector<pair<int, int>>& points_x, const vector<pair<int, int>>& points_y) {
    int n = points_x.size();
    
    if (n <= 3) {
        return brute_force(points_x);
    }

    int mid_x = points_x[n / 2].first;
    
    vector<pair<int, int>> left_x(points_x.begin(), points_x.begin() + n / 2);
    vector<pair<int, int>> right_x(points_x.begin() + n / 2, points_x.end());
    
    vector<pair<int, int>> left_y, right_y;
    for (const auto& point : points_y) {
        if (point.first < mid_x)
            left_y.push_back(point);
        else
            right_y.push_back(point);
    }

    int left_min = closest_pair_rec(left_x, left_y);
    int right_min = closest_pair_rec(right_x, right_y);
    
    int delta = min(left_min, right_min);
    
    vector<pair<int, int>> strip;
    for (const auto& point : points_y) {
        if (abs(point.first - mid_x) < delta) {
            strip.push_back(point);
        }
    }

    int strip_min = delta;
    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && j < i + 8; ++j) {
            int dist = chebyshev_distance(strip[i], strip[j]);
            strip_min = min(strip_min, dist);
        }
    }

    return min(delta, strip_min);
}

int max_square_size(vector<pair<int, int>>& positions) {
    if (positions.size() <= 1) return INT_MAX;
    
    vector<pair<int, int>> points_x = positions;
    vector<pair<int, int>> points_y = positions;
    
    sort(points_x.begin(), points_x.end());
    sort(points_y.begin(), points_y.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    return closest_pair_rec(points_x, points_y);
}

void solve_case() {
    int n;
    cin >> n;
    vector<pair<int, int>> positions(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> positions[i].first >> positions[i].second;
    }
    
    cout << max_square_size(positions) << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve_case();
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <iomanip> 

using namespace std;

struct Planet {
    int x, y;
    string faction;
};

double euclidean_distance(const Planet &p1, const Planet &p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double brute_force(const vector<Planet> &planets_lgu, const vector<Planet> &planets_cai) {
    if (planets_lgu.empty() || planets_cai.empty()) return numeric_limits<double>::infinity();

    double min_dist = numeric_limits<double>::infinity();
    for (const auto &lgu : planets_lgu) {
        for (const auto &cai : planets_cai) {
            min_dist = min(min_dist, euclidean_distance(lgu, cai));
        }
    }
    return min_dist;
}

double closest_rival_planets(vector<Planet> &all_planets, vector<Planet> &planets_lgu, vector<Planet> &planets_cai) {
    int n = all_planets.size();
    
    if (n <= 3) return brute_force(planets_lgu, planets_cai);

    int mid = n / 2;
    int mid_x = all_planets[mid].x;

    vector<Planet> left_planets(all_planets.begin(), all_planets.begin() + mid);
    vector<Planet> right_planets(all_planets.begin() + mid, all_planets.end());

    vector<Planet> left_lgu, right_lgu, left_cai, right_cai;
    
    for (const auto &p : planets_lgu) (p.x < mid_x ? left_lgu : right_lgu).push_back(p);
    for (const auto &p : planets_cai) (p.x < mid_x ? left_cai : right_cai).push_back(p);

    double left_min = closest_rival_planets(left_planets, left_lgu, left_cai);
    double right_min = closest_rival_planets(right_planets, right_lgu, right_cai);

    double delta = min(left_min, right_min);
    
    vector<Planet> strip_lgu, strip_cai;
    for (const auto &p : planets_lgu) if (abs(p.x - mid_x) < delta) strip_lgu.push_back(p);
    for (const auto &p : planets_cai) if (abs(p.x - mid_x) < delta) strip_cai.push_back(p);

    sort(strip_lgu.begin(), strip_lgu.end(), [](const Planet &a, const Planet &b) { return a.y < b.y; });
    sort(strip_cai.begin(), strip_cai.end(), [](const Planet &a, const Planet &b) { return a.y < b.y; });

    double strip_min = delta;
    for (const auto &lgu : strip_lgu) {
        for (const auto &cai : strip_cai) {
            if (cai.y > lgu.y + delta) break;
            strip_min = min(strip_min, euclidean_distance(lgu, cai));
        }
    }

    return min(delta, strip_min);
}

void solve_case() {
    int n;
    cin >> n;
    if (n == 0) return;

    vector<Planet> planets, planets_lgu, planets_cai;

    for (int i = 0; i < n; i++) {
        int x, y;
        string faction;
        cin >> x >> y >> faction;
        Planet p = {x, y, faction};
        planets.push_back(p);

        if (faction == "LGU") planets_lgu.push_back(p);
        else planets_cai.push_back(p);
    }

    if (planets_lgu.empty() || planets_cai.empty()) {
        cout << "INF" << endl;
        return;
    }

    sort(planets.begin(), planets.end(), [](const Planet &a, const Planet &b) { return a.x < b.x; });

    double min_dist = closest_rival_planets(planets, planets_lgu, planets_cai);
    cout << fixed << setprecision(1) << min_dist << endl;
}

int main() {
    while (true) {
        solve_case();
        if (cin.eof()) break;
    }
    return 0;
}

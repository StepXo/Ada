#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int casos;
    cin >> casos;
    while (casos--) {
        int n;
        cin >> n;

        vector<int> precios(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> precios[i]; 
        }

        vector<int> dpMax(n + 1, 0);
        vector<int> dpMin(n + 1, INT_MAX); 
        dpMin[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dpMax[i] = max(dpMax[i], precios[j] + dpMax[i - j]);
                dpMin[i] = min(dpMin[i], precios[j] + dpMin[i - j]);
            }
        }

        cout << dpMin[n] << " " << dpMax[n] << endl;
    }

    return 0;
}

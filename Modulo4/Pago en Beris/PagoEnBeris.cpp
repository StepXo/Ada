#include <iostream>
#include <vector>

using namespace std;

int main() {
    int entrada;
    cin >> entrada;
    vector<int> num = {10000, 5000, 1000, 500, 100, 50, 10, 5, 1};

    for (int i = 0; i < entrada; i++) {
        long long beri;
        cin >> beri;

        long long contador = 0;
        int aux = 0;

        while (beri > 0) {
            if (num[aux] <= beri) {
                contador += beri / num[aux];
                beri %= num[aux];
            } else {
                aux++;
            }
        }

        cout << contador << endl;
    }

    return 0;
}

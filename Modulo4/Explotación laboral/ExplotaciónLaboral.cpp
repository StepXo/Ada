#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Trabajo {
    double multa;
    double tiempo;  
};

int main() {
    int C; 
    cin >> C;

    while (C--) {
        int N; 
        cin >> N;

        vector<Trabajo> trabajos(N);
        for (int i = 0; i < N; i++) {
            cin >> trabajos[i].tiempo >> trabajos[i].multa;
        }

        sort(trabajos.begin(), trabajos.end(), [](const Trabajo &a, const Trabajo &b) {
            return a.multa/a.tiempo > b.multa/b.tiempo;
        });

        long long tiempo_total = 0;
        long long multa_total = 0;          
        for (const auto &trabajo : trabajos) {

            multa_total += tiempo_total * trabajo.multa;
            tiempo_total += trabajo.tiempo;
        }
        

        cout << multa_total << endl;
    }

    return 0;
}

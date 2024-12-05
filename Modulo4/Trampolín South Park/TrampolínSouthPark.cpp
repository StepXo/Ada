#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Niño {
    long id;
    double tiempo;  
    double pataleta;

};

int main() {
    int C; 
    cin >> C;

    while (C--) {
        int N; 
        cin >> N;

        vector<Niño> niños(N);
        for (int i = 0; i < N; i++) {
            cin >> niños[i].tiempo >> niños[i].pataleta;
            niños[i].id = i;
        }

        sort(niños.begin(), niños.end(), [](const Niño &a, const Niño &b) {
            if (a.pataleta != b.pataleta) return a.pataleta > b.pataleta;
            return a.tiempo < b.tiempo;
        });

        vector<int> cronograma(N, -1);


        long long pataleta_total = 0;
        int Left_spaces = N - 1;

        for (int i = 0; i < N; i++) {
            int p = niños[i].tiempo/10;


            while (cronograma[p] != -1) {
                p--;
            }

            if (p >= 0) {
                cronograma[p] = niños[i].id;
                continue;
            }

            while (cronograma[Left_spaces] != -1) {
                Left_spaces--;
            }

            cronograma[Left_spaces] = niños[i].id;
            pataleta_total += niños[i].pataleta;
            Left_spaces--;
        }

        cout << pataleta_total <<endl;
    }

    return 0;
}

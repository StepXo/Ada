#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct Barco {
    int inicio;
    int fin;
};

int main() {
    int C; 
    cin >> C;

    while (C!=0) {

        vector<Barco> barcos(C);

        for (int i = 0; i < C; i++) {
            cin >> barcos[i].inicio >> barcos[i].fin;
        }

        sort(barcos.begin(), barcos.end(), [](const Barco &a, const Barco &b) {
            return a.fin < b.fin;
        });


        int balas = 0; 
        int inicio = 0; 

        for (const auto &barco : barcos) {

            if (barco.inicio <= inicio){
                continue;
            }
            inicio = barco.fin;
            balas++;
        }

        cout << balas << endl;
        cin >> C;
    }

    return 0;
}

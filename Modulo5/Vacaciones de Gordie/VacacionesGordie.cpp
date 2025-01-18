#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct Familiar {
    int fecha;
    int hora_inicio;
    int hora_fin;
};

int convertirHora(const string& horaStr) {
    stringstream ss(horaStr);
    string horas, minutos;
    getline(ss, horas, ':');
    getline(ss, minutos);

    int h = stoi(horas);
    int m = stoi(minutos);

    return h*60 + m;
}

int main() {
    int C; 
    cin >> C;
     map<string, int> diaSemana = {
        {"sabado", 1},
        {"domingo", 2},
        {"lunes", 3}
    };

    while (C--) {
        int N; 
        cin >> N;

        vector<Familiar> familiares(N);

        for (int i = 0; i < N; i++) {
            string fechaStr, horaStr;
            int tiempo;

            cin >> fechaStr >> horaStr >> tiempo;
            int hora = convertirHora(horaStr);

            familiares[i].fecha = diaSemana[fechaStr];
            familiares[i].hora_inicio = hora;
            familiares[i].hora_fin = hora + tiempo;
        }

        sort(familiares.begin(), familiares.end(), [](const Familiar &a, const Familiar &b) {
            if (a.fecha != b.fecha) return a.fecha < b.fecha;
            if (a.hora_fin != b.hora_fin) return a.hora_fin < b.hora_fin;
            return a.hora_inicio < b.hora_inicio;
        });

        int trasnocho = 1440;
        int dia = 1;
        int hora = 360;
        int acum = 0;

        for (const auto &familiar : familiares) {
            if (familiar.fecha!=dia){
                hora = 360;
                dia ++;
            }

            if (familiar.hora_inicio < hora){
                continue;
            }

            if (familiar.hora_fin > trasnocho){
                continue;
            }

            hora = familiar.hora_fin;
            acum++;

        }

        cout << acum << endl;

    }

    return 0;
}

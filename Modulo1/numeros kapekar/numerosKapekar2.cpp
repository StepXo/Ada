#include <iostream>
#include <cmath>

int length(long long numero) {
    if (numero == 0) return 1;
    return floor(log10(abs(numero))) + 1;
}

int main() {
    int casos;
    std::cin >> casos;

    long long entrada = 0;



    for (int i = 0; i < casos; i++) {
        std::cin >> entrada;

        if (entrada<4){
            std::cout << "NO" << std::endl;
            continue;
        }

        double B = 0;
        double I = 10;

        while(B<I){
            if(B>0 && std::abs(B - static_cast<long long>(B))<1e-9 ){
                std::cout << "KAP" << std::endl;
                break;
            }

            double BAux = ((entrada*(entrada-I))/(1-I));
            if (std::abs(BAux-B)<1){
                std::cout << "NO" << std::endl;
                break;
            }

            B = BAux;
            I*=10;
        }

    }

    return 0;
}

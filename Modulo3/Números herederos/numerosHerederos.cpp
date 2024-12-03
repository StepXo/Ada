#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream> 

using namespace std;

vector<int> numberToVector(long long number) {
    vector<int> digits;
    string numStr = to_string(number); 

    for (char digit : numStr) {
        int num = digit - '0';

        auto it = lower_bound(digits.begin(), digits.end(), num);
        digits.insert(it, num);
    }

    return digits;
}

bool validate(vector<int>& c, long long& number) {
    int n = c.size();
    int mitad = n / 2;

    long long derecha = 0;
    long long izquierda = 0;

    long long aux = 1;
    for (int i = 0; i < mitad; i++) {
        izquierda += c[i]*aux;
        aux*=10;
    }

    aux = 1;
    for (int i = mitad; i < n; i++) {
        derecha += c[i]*aux;
        aux*=10;
    }

    return derecha*izquierda == number;
}



int main(){

    int entrada;
    cin>>entrada;
    cin.ignore();

    for (int i = 0; i<entrada; i++){

        long long number;
        cin>>number;
        vector<int> nums = numberToVector(number);
        bool valid = false;
        do {
            if(validate(nums,number)){
                valid = true;
                break;
            }
        } while (next_permutation(nums.begin(), nums.end()));

        if (valid){
            cout<<"Heredero"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
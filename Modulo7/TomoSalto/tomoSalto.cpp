#include <iostream>

using namespace std;

int main(){
    int casos;
    cin >> casos;
    while (casos--){

        int entrada;
        cin>>entrada;

        int tomo = 0;
        int noTomo = 0;

        while (entrada--){
            int nueva;
            cin>>nueva;

            int nuevoTomo = noTomo + nueva; 

            noTomo = max(tomo, noTomo); 
            tomo = nuevoTomo;  
        }

        cout<<max(tomo, noTomo) <<endl;
    }
    
    return 0;
}
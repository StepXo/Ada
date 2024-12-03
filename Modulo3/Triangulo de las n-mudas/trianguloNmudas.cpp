#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream> 

using namespace std;

void entry_processing(long long& size,vector<long long>& numeros) {
    string line;
    getline(cin, line);
    istringstream stream(line);
    bool entry = false;
    long long num;
    while (stream >> num) {
        if (!entry){
            entry = true;
            size = num;
            continue;
        }
        numeros.push_back(num);
    }
}

bool validate(vector<long long>& c, long long& size){
    if (c[0]+c[1]+c[2]+c[3] != size){
        return false;
    }

    if (c[3]+c[4]+c[5]+c[6] != size){
        return false;
    }

    if (c[6]+c[7]+c[8]+c[0] != size){
        return false;
    }

    return true;
}



int main(){
    long long size = 0;

    int entrada;
    cin>>entrada;
    cin.ignore();

    for (int i = 0; i<entrada; i++){
        vector<long long> nums = {};
        long long contador = 0;

        entry_processing(size,nums);
        sort(nums.begin(), nums.end());

        do {
            if(validate(nums,size)){
                contador++;
            }
        } while (next_permutation(nums.begin(), nums.end()));

        cout<<contador<<endl;
    }
    return 0;
}
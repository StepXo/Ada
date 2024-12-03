#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream> 

using namespace std;

void entry_processing(long long& time,vector<long long>& numeros) {

    string line;
    getline(cin, line);
    istringstream stream(line);

    bool entry = false;
    long long num;
    while (stream >> num) {
        if (!entry){
            entry = true;
            time = num;
            continue;
        }
        numeros.push_back(num);        
    }
}

void branch_bound(vector<long long>& nums, long long time, long long sum, time_t i, long long& min) {

    long long current_difference = time - sum;

    if (current_difference < 0) {
        return;
    }

    if (current_difference < min) {
        min = current_difference;
    }

    if (min == 0) {
        return;
    }

    if (i == nums.size()) {
        return;
    }

    branch_bound(nums, time, sum + nums[i], i + 1, min);
    branch_bound(nums, time, sum, i + 1, min);
}



int main(){
    long long time = 0;

    int entrada;
    cin>>entrada;
    cin.ignore();

    for (int i = 0; i<entrada; i++){
        vector<long long> nums = {};
        long long contador = LLONG_MAX;

        entry_processing(time,nums);
        branch_bound(nums, time, 0, 0, contador);

        cout<<contador<<endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>

using namespace std;

void entry_processing(vector<long long>& numeros){

    string line;
    getline(cin, line);
    istringstream stream(line);

    int num;
    while (stream >> num) {
        numeros.push_back(num);
    }
}

long long mcm(long long a, long long b){
    return (a / gcd(a, b)) * b; //O(log(max(a,b)))
}

long long mcm_multiple(const vector<long long>& nums){

    if (nums.empty()) return 0; 

    long long result = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) { //O(n) para N numeros
        result = lcm(result, nums[i]);
    }

    return result;
}

int main() {

    int casos;
    cin >> casos;
    cin.ignore();

    for (int i = 0; i<casos;i++){
        vector<long long> numeros = {};
        entry_processing(numeros);

        cout << mcm_multiple(numeros) << endl;

    }

    
    return 0;
}

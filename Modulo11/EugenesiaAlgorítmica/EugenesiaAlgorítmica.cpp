#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countInversions(const string& seq) {
    int inversions = 0;
    for (size_t i = 0; i < seq.size(); i++) {
        for (size_t j = i + 1; j < seq.size(); j++) {
            if (seq[i] > seq[j]) {
                inversions++;
            }
        }
    }
    return inversions;
}

struct Individual {
    string sequence;
    int defect_level;
    
    bool operator<(const Individual& other) const {
        if (defect_level != other.defect_level) {
            return defect_level < other.defect_level;
        }
        return sequence < other.sequence;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<Individual> individuals(N);
    
    for (int i = 0; i < N; i++) {
        cin >> individuals[i].sequence;
        individuals[i].defect_level = countInversions(individuals[i].sequence);
    }
    
    sort(individuals.begin(), individuals.end());
    
    for (int i = 0; i < M; i++) {
        cout << individuals[i].sequence << "\n";
    }
    
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FenwickTree {
private:
    vector<int> BIT;
    int size;

public:
    FenwickTree(int n) : size(n) {
        BIT.assign(n + 1, 0);
    }

    void update(int index, int value) {
        while (index <= size) {
            BIT[index] += value;
            index += index & -index;
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += BIT[index];
            index -= index & -index;
        }
        return sum;
    }
};

int countInversions(string seq) {
    vector<int> ranks(seq.size());
    vector<char> sorted_seq(seq.begin(), seq.end());
    sort(sorted_seq.begin(), sorted_seq.end());
    
    for (size_t i = 0; i < seq.size(); i++) {
        ranks[i] = lower_bound(sorted_seq.begin(), sorted_seq.end(), seq[i]) - sorted_seq.begin() + 1;
    }
    
    FenwickTree fenwick(seq.size());
    int inversions = 0;
    for (int i = seq.size() - 1; i >= 0; i--) {
        inversions += fenwick.query(ranks[i] - 1);
        fenwick.update(ranks[i], 1);
    }
    return inversions;
}

struct Individual {
    string sequence;
    int defect_level;
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<Individual> individuals(N);
    
    for (int i = 0; i < N; i++) {
        cin >> individuals[i].sequence;
        individuals[i].defect_level = countInversions(individuals[i].sequence);
    }
    
    sort(individuals.begin(), individuals.end(), [](const Individual& a, const Individual& b) {
        return a.defect_level < b.defect_level || (a.defect_level == b.defect_level && a.sequence < b.sequence);
    });
    
    for (int i = 0; i < M; i++) {
        cout << individuals[i].sequence << "\n";
    }
    
    return 0;
}
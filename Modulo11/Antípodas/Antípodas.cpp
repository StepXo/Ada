#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void processQueries(const vector<string>& words, const vector<int>& queries) {
    vector<string> sorted_words = words;
    sort(sorted_words.begin(), sorted_words.end());
    
    for (int i : queries) {
        cout << sorted_words[i - 1] << " " << sorted_words[sorted_words.size() - i] << "\n";
    }
}

int main() {
    int N, C;
    cin >> N >> C;
    
    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }
    
    vector<int> queries(C);
    for (int i = 0; i < C; i++) {
        cin >> queries[i];
    }
    
    processQueries(words, queries);
    
    return 0;
}

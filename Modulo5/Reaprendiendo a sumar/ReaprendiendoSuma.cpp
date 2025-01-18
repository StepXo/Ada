#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    long value;  
    long weight;
    Node* left;
    Node* right;

    Node(long c, long f) : value(c), weight(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->value > b->value;
    }
};

int main() {
    int N;
    cin >> N;
    while (N!=0){

        priority_queue<Node*, vector<Node*>, Compare> Q;

        long A;
        for (int i = 0; i < N; i++) {
            cin >> A;

            Node* x = new Node(A, 0);
            Q.push(x);
        }

        for (int i = 0; i < N - 1; i++) {
            Node* x = new Node(0, 0);

            x->left = Q.top();
            Q.pop();

            x->right = Q.top();
            Q.pop();

            x->value = x->left->value + x->right->value;
            x->weight = x->left->weight + x->right->weight + x->value;

            Q.push(x);
        }

        cout << Q.top()->weight << endl;
        
        cin >> N;
    }

    return 0;
}

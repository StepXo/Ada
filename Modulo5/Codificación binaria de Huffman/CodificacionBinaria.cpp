#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    string value;  
    long long weight;
    Node* left;
    Node* right;

    Node(string c, long long f) : value(c), weight(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        if (a->weight == b->weight) return a->value > b->value;
        return a->weight > b->weight;
    }
};

void printLeafNodes(Node* node,const string& bin) {
    if (!node) return;

    printLeafNodes(node->left,bin + "0");

    if (!node->left && !node->right) {
        cout << node->value << " "<< bin << endl;
        return;
    }
    
    printLeafNodes(node->right,bin + "1");
}

int main() {
    int C;
    cin >> C;
    int j = 1;

    while (C--){    
        int N;
        cin >> N;

        priority_queue<Node*, vector<Node*>, Compare> Q;
        string A;
        long long f;
        for (int i = 0; i < N; i++) {
            cin >> A >> f;

            Node* x = new Node(A, f);
            Q.push(x);
        }

        for (int i = 0; i < N - 1; i++) {
            Node* x = new Node("", 0);

            x->left = Q.top();
            Q.pop();

            x->right = Q.top();
            Q.pop();

            x->value = x->left->value + x->right->value;

            x->weight = x->left->weight + x->right->weight;

            Q.push(x);
        }
        cout << "caso "<<j<<":"<<endl;
        printLeafNodes(Q.top(),"");
        j++;
        cout<<endl;
    }

    return 0;
}

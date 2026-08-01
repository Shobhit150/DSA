#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};


class Solution {
public:
    struct Compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;   // Min Heap
        }
    };

    Node* flatten(Node* head) {
        if (!head)
            return nullptr;

        priority_queue<Node*, vector<Node*>, Compare> pq;

        Node* curr = head;
        while (curr) {
            pq.push(curr);
            curr = curr->next;
        }

        Node dummy(0);
        Node* tail = &dummy;

        while (!pq.empty()) {
            Node* node = pq.top();
            pq.pop();

            tail->bottom = node;
            tail = tail->bottom;

            tail->next = nullptr;

            if (node->bottom)
                pq.push(node->bottom);
        }

        return dummy.bottom;
    }
};

void solve() {
    
}

int main() {

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);
        Node* tail = dummy;
        unordered_map<Node*, Node*> mp;

        Node* tmp = head;
        while(tmp) {
            tail->next = new Node(tmp->val);
            tail = tail->next;
            mp[tmp] = tail;
            tmp = tmp->next;
        }
        tmp = head;
        tail = dummy;
        while(tmp) {
            tail = tail->next;

            tail->random = mp[tmp->random];

            tmp = tmp->next;
        }
        return dummy->next;
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
#include <iostream>
#include <vector>
using namespace std;


class Node {
    public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    Node* rotate(Node* head, int k) {

        if (!head || !head->next || k == 0)
            return head;
        int n = 1;
        Node* tail = head;
        while (tail->next) {
            tail = tail->next;
            n++;
        }

        k %= n;
        if (k == 0)
            return head;
        Node* curr = head;
        for (int i = 1; i < k; i++)
            curr = curr->next;

        Node* newHead = curr->next;
        curr->next = nullptr;
        tail->next = head;

        return newHead;
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
#include <iostream>
#include <vector>
using namespace std;


class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};


class Solution {
public:
    ListNode* oddEvenList(ListNode* &head) {
        ListNode* odd = head;
        ListNode* even = odd->next;
        ListNode* evenHead = even;

        while(even && even->next) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
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
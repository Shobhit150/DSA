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
    ListNode* addTwoNumbers(ListNode* &linkedList1, ListNode* &linkedList2) {
        int carry = 0;
        ListNode* ans = new ListNode();
        while(linkedList1 || linkedList2 || carry != 0) {
            int val = carry;
            if(linkedList1) {
                val += linkedList1->data;
                linkedList1 = linkedList1->next;
            }
            if(linkedList2) {
                val += linkedList2->data;
                linkedList2 = linkedList2->next;
            }
            carry = val/10;
            ans->next = new ListNode(val%10);
        }
        return ans->next;
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
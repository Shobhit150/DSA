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
    ListNode* sortList(ListNode* &head) {
        
        ListNode* dummy0 = new ListNode();
        ListNode* zero = dummy0;
        ListNode* dummy1 = new ListNode();
        ListNode* one = dummy1;
        ListNode* dummy2 = new ListNode();
        ListNode* two = dummy2;

        ListNode* tmp = head;
        while(tmp) {
            if(tmp->data == 0) {
                dummy0->next = tmp;
                dummy0 = dummy0->next;
            } else if(tmp->data == 1) {
                dummy1->next = tmp;
                dummy1 = dummy1->next;
            } else {
                dummy2->next = tmp;
                dummy2 = dummy2->next;
            }
            tmp = tmp->next;
        }
        dummy0->next = (one->next) ? one->next : two->next;
        dummy1->next = two->next;
        dummy2->next = nullptr;

        return zero->next;

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
#include <iostream>
#include <vector>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};


class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if(l1) {
            tail->next = l1;
        }
        if(l2) {
            tail->next = l2;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;

        while(fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = nullptr;

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        return merge(l1, l2);
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
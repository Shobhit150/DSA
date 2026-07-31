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
    ListNode* reverse(ListNode *head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;

    }
    ListNode *addOne(ListNode *head) {
        head = reverse(head);
        int carry = 1;
        ListNode* tmp = head;
        ListNode* prev = nullptr;
        while(carry != 0 && tmp) {
            prev = tmp;
            if(tmp->val < 9) {
                tmp->val += 1;
                carry = 0;
            } else {
                tmp->val = 0;
                tmp = tmp->next;
            }
        }
        if(carry) {
            prev->next = new ListNode(1);
        }
        head = reverse(head);
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
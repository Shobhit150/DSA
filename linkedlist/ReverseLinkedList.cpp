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
    ListNode* reverseList(ListNode* head) {
        ListNode* tmp = head;
        ListNode* prev = nullptr;
        while(tmp) {
            ListNode* node = tmp->next;
            tmp->next = prev;
            prev = tmp;
            tmp = node;
        }
        return prev;
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
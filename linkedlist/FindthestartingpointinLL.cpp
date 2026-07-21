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
    ListNode *findStartingPoint(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        if(!fast || !fast->next) return nullptr;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(!fast || !fast->next) return nullptr;
            if(fast == slow) break;
        }

        ListNode* tmp = head;

        while(slow != tmp) {
            slow = slow->next;
            tmp = tmp->next;
        }

        return tmp;
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
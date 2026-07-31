#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

class Solution {
public:
    ListNode* deleteAllOccurrences(ListNode* head, int target) {
        ListNode* curr = head;
        while(curr) {
            ListNode* next = curr->next;
            if(curr->val == target) {
                if(curr->prev) {
                    curr->prev->next = curr->next;
                } else {
                    head = curr->next;
                }

                if(curr->next) {
                    curr->next->prev = curr->prev;
                }
                delete curr;
            }
            curr = next;
        }
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
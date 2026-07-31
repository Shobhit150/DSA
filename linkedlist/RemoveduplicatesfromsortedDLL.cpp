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
    ListNode * removeDuplicates(ListNode *head) {

        ListNode* tmp = head;

        while(tmp && tmp->next) {
            if(tmp->val == tmp->next->val) {
                ListNode* del = tmp->next;
                tmp->next = del->next;
                if(del->next) {
                    del->next->prev = tmp;
                }
                delete del;
                continue;
            }
            tmp=tmp->next;
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
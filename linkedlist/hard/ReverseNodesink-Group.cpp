#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;


        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* curr = head;
        ListNode* tmp = head;
        ListNode* prev = nullptr;
        
        while(curr) {
            ListNode* tmp = curr;
            ListNode* tmpHead = tmp;
            int cnt = 1;
            while(cnt < k && tmp->next) {
                tmp = tmp->next;
                cnt++;
            }
            if(cnt < k)
                break;
            ListNode* nextGroup = tmp->next;
            tmp->next = nullptr;
            ListNode* newHead = reverse(tmpHead);
            if(prev == nullptr) {
                head = newHead;
            } else {
                prev->next = newHead;
            }

            tmpHead->next = nextGroup;
            prev = tmpHead;
            curr = nextGroup;
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
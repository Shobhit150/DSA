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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        while(fast && fast->next) {
            ListNode* tmp = slow;
            slow = slow->next;
            fast = fast->next->next;
            tmp->next = prev;
            prev = tmp;
        }
        if(fast) {
            slow = slow->next;
        }
        while(slow && prev) {
            if(slow->val != prev->val) return false;
            slow = slow->next;
            prev = prev->next;
        }
        return true;
    }
};

void solve() {
    Solution s;

    // Test Case 1: Palindrome
    // 1 -> 2 -> 3 -> 2 -> 1
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(2);
    head1->next->next->next->next = new ListNode(1);

    cout << s.isPalindrome(head1) << endl;   // Expected: 1

    // Test Case 2: Not a palindrome
    // 1 -> 2 -> 3 -> 4
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);

    cout << s.isPalindrome(head2) << endl;   // Expected: 0

    // Test Case 3: Even length palindrome
    // 1 -> 2 -> 2 -> 1
    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(2);
    head3->next->next = new ListNode(2);
    head3->next->next->next = new ListNode(1);

    cout << s.isPalindrome(head3) << endl;   // Expected: 1

    // Test Case 4: Single node
    // 5
    ListNode* head4 = new ListNode(5);

    cout << s.isPalindrome(head4) << endl;   // Expected: 1

    // Test Case 5: Two nodes (not palindrome)
    // 1 -> 2
    ListNode* head5 = new ListNode(1);
    head5->next = new ListNode(2);

    cout << s.isPalindrome(head5) << endl;   // Expected: 0
}

int main() {

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

class ListNode {
public:
    int data;
    ListNode* prev;
    ListNode* next;

    ListNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};


class Solution {
public:
    ListNode* reverseDLL(ListNode* head) {
        ListNode* tmp = head;
        ListNode* pre;
        while(tmp) {
            pre = tmp;
            tmp = tmp->next;
            pre->next = pre->prev;
            pre->prev = tmp;
        }
        return pre;
    }
};
#include <iostream>
#include <vector>
using namespace std;

class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node* slow = head;
        Node* fast = head;
        if(!fast || !fast->next) return 0;
        
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(!fast || !fast->next) return 0;
            if(fast == slow) break;
        }

        int cnt = 1;
        slow = fast->next;
        while(slow != fast) {
            cnt++;
            slow = slow->next;
            
        }
        return cnt;
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
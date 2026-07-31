#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Given the head of a sorted doubly linked list of positive distinct integers, and a target integer, return a 2D array containing all unique pairs of nodes (a, b) such that a + b == target.

// Each pair should be returned as a 2-element array [a, b] with a < b. The list is sorted in ascending order. If there are no such pairs, return an empty list.

// Example 1

// Input: head = [1, 2, 4, 5, 6, 8, 9], target = 7

// Output: [[1, 6], [2, 5]]

// Explanation:

// 1 + 6 = 7 and 2 + 5 = 7 are the valid pairs.

// Example 2

// Input: head = [1, 5, 6], target = 6

// Output: [[1, 5]]

// Explanation:

// 1 + 5 = 6 is the only valid pair.

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev; 

    ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}

    ~ListNode() {
        delete next;
    }
};


class Solution {
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        vector<vector<int>> ans;

        ListNode* left = head;
        ListNode* right = head;
        while(right->next) {
            right = right->next;
        }

        while(left != right && left->prev != right) {
            int sum = left->val + right->val;
            if(sum == target) {
                ans.push_back({left->val, right->val});
                left=left->next;
                right= right->prev;
            }
            if(sum > target) {
                right = right->prev;
            }
            if(sum<target) {
                left = left->next;
            }
        }
        return ans;
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
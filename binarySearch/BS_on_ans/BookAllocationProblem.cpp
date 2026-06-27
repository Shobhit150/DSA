#include <iostream>
#include <vector>
using namespace std;

// Book Allocation Problem
// Subscribe to TUF+

// Hints
// Company
// Given an array nums of n integers, where nums[i] represents the number of pages in the i-th book, and an integer m representing the number of students, allocate all the books to the students so that each student gets at least one book, each book is allocated to only one student, and the allocation is contiguous.

// Allocate the books to m students in such a way that the maximum number of pages assigned to a student is minimized. If the allocation of books is not possible, return -1.

// Example 1

// Input: nums = [12, 34, 67, 90], m=2

// Output: 113

// Explanation: The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.

class Solution {
public:
    bool check(vector<int> &nums, int mid, int m) {
        int cnt = 1;
        int n = nums.size();
        int sumi = 0;
        for(int i=0;i<n;i++) {
            if(sumi + nums[i] > mid) {
                sumi = 0;
                cnt++;
            }

            sumi += nums[i];
        }

        return cnt <= m;
    }
    int findPages(vector<int> &nums, int m)  {
        int l = 0;
        int n = nums.size();
        int r = 0;
        int ans = -1;
        for(int i=0;i<n;i++) {
            l = max(l,nums[i]);
            r += nums[i];
        }
        while(l<=r) {
            int mid = (l+r)/2;
            if(check(nums, mid, m)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
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
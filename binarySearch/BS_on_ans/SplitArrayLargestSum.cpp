#include <iostream>
#include <vector>
using namespace std;

// 410. Split Array Largest Sum
// Hard
// Topics
// premium lock icon
// Companies
// Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

// Return the minimized largest sum of the split.

// A subarray is a contiguous part of the array.

// Input: nums = [7,2,5,10,8], k = 2
// Output: 18
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

class Solution {
public:
    bool check(vector<int> nums, int mid, int k) {
        int n = nums.size();
        int cnt = 1;
        int sumi = 0;
        for(int i=0;i<n;i++) {
            if(sumi + nums[i] > mid) {
                cnt++;
                sumi = 0;
            }
            sumi += nums[i];
        }
        return cnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int ans = -1;
        for(int i=0;i<n;i++) {
            l = max(l, nums[i]);
            r += nums[i];
        }

        while(l<=r) {
            int mid = (l+r)/2;

            if(check(nums, mid, k)) {
                ans = mid;
                r = mid - 1;
            } else {
                l  = mid + 1;
            }
        }
        return ans;

    }
};

void solve() {
    vector<int> nums = {7,2,5,10,8};
    Solution s;
    s.splitArray(nums, 2);
}

int main() {

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
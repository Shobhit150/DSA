#include <iostream>
#include <vector>
#include<cmath>
using namespace std;

// Given a sorted array arr of size n, containing integer positions of n gas stations on the X-axis, and an integer k, place k new gas stations on the X-axis.

// The new gas stations can be placed anywhere on the non-negative side of the X-axis, including non-integer positions.

// Let dist be the maximum distance between adjacent gas stations after adding the k new gas stations.

// Find the minimum value of dist.

// (a + b - 1)/b
// Your answer will be accepted if it is within 1e-6 of the true value.
// Example 1
// Input: n = 10, arr = [1, 2, 3, 4, 5, 6 ,7, 8, 9, 10], k = 10
// Output: 0.50000
// Explanation:
// One of the possible ways to place 10 gas stations is [1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5, 10].
// Thus the maximum difference between adjacent gas stations is 0.5.
// Hence, the value of dist is 0.5.
// It can be shown that there is no possible way to add 10 gas stations in such a way that the value of dist is lower than this.

class Solution {
public:
    bool check(vector<int> &arr, double mid, int k) {
        int n = arr.size();
        int cnt = 0;
        for(int i=0;i<n-1;i++) {
            int gap = arr[i+1] - arr[i];
            int times = ceil(gap/mid) - 1;
            cnt += times;
        }
        return cnt <= k;
    }
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        double l = 0;
        int n = arr.size();
        double r = 0;
        int ans = -1;
        for(int i=0;i<n-1;i++) {
            double gap = (arr[i+1] - arr[i]);
            r = max(r, gap);
        }
        while(l<=r) {
            double mid = (r+l)/2;

            if(check(arr, mid, k)) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

void solve() {
    Solution s;
    vector<int> nums = { 1, 2, 3, 4, 5, 6 ,7, 8, 9, 10 };
    cout << s.minimiseMaxDistance(nums, 10);
}

int main() {

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
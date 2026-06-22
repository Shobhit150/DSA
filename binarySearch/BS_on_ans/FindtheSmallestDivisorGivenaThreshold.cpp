#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValid(vector<int>& nums, int threshold, int mid) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++) {
            cnt += (nums[i] + mid - 1)/mid;
        }

        return cnt <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = *max_element(nums.begin(), nums.end());

        int l = 1;
        int r = maxi;
        int ans = -1;
        while(l<=r) {
            int mid = (l+r)/2;
            if(isValid(nums, threshold, mid)) {
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
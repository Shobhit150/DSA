#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool check(vector<int> &nums,int mid, int k) {
        int cnt = 1;
        int n = nums.size();

        int curr = 0;

        for(int i=1;i<n;i++) {
            if(nums[i] - nums[curr] >= mid) {
                cnt++;
                curr = i;
            }  
        }
        return cnt >= k;
    }
    int aggressiveCows(vector<int> &nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.back() - nums.front();
        int ans = 0;

        while(l <= r) {
            int mid = (l+r)/2;
            if(check(nums, mid, k)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
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
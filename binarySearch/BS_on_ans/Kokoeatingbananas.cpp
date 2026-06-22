#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long timeToEat(vector<int>& nums, int t) {
        long long ans = 0;
        for(int i=0;i<nums.size();i++) {
            
            ans += (nums[i] + t - 1)/t;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(), piles.end());
        int l = 1;
        int r = maxi;
        int ans = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            long long val = timeToEat(piles, mid);
            if(val <= h) {
                ans = mid;
                r = mid -1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};


void solve() {
    Solution s;
    vector<int> piles = {30,11,23,4,20};
    cout << s.minEatingSpeed(piles, 5);
}

int main() {

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
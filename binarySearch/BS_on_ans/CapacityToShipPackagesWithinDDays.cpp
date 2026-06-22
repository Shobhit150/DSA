#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValid(vector<int>& weights, int mid, int days) {
        int cnt = 1;
        int sumi = 0;
        for(int i=0;i<weights.size();i++) {
            if(sumi + weights[i] > mid) {
                cnt++;
                sumi = 0;
            }
            sumi += weights[i];
        }
        return cnt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int l = *max_element(weights.begin(), weights.end());
        int tot = 0;
        int ans = -1;
        for(int i=0;i<n;i++) {
            tot += weights[i];
        }
        int r = tot;

        while(l<=r) {
            int mid = (l+r)/2;
            if(isValid(weights, mid, days)) {
                r = mid-1;
                ans = mid;
            } else {
                l = mid+1;
            }
        }
        return ans;
    }
};

void solve() {
    Solution s;
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    s.shipWithinDays(nums, 5);
}

int main() {

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
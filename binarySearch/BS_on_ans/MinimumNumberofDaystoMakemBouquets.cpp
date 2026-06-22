#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isvalid(vector<int>& bloomDay, int mid, int m, int k) {
        int n = bloomDay.size();
        int cnt = 0;
        int bouquet = 0;
        for(int i=0;i<n;i++) {
            
            if(bloomDay[i] <= mid) {
                cnt++;
            } else {
                cnt = 0;
            }

            if(cnt == k) {
                bouquet++;
                cnt = 0;
            }
        }
        return bouquet >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());

        int l = 1;
        int r = maxi;
        int ans = -1;
        while(l<=r) {
            int mid = (l+r)/2;
            if(isvalid(bloomDay, mid, m, k)) {
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
    vector<int> nums = {1,10,3,10,2};
    Solution s;
    s.minDays(nums, 3, 1);
}

int main() {

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
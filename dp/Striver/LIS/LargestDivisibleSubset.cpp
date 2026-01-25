#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> tab(vector<int> &nums) {
        int maxi = 1;
        int n = nums.size();
        vector<int> dp(n+1, 1);
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    maxi = max(maxi, dp[i]);
                }
            }
        }
        vector<int> ans;

        for(int i=n-1;i>=0;i--) {
            if(dp[i] == maxi) {
                ans.push_back(dp[i]);
                maxi--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        return tab(nums);
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,4,8};
    vector<int> ans = s.largestDivisibleSubset(nums);
    for(int i=0;i<nums.size();i++) {
        cout << ans[i] << " ";
    }
}
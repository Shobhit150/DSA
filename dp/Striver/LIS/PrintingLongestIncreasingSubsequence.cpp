#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int memo(vector<int>& nums, int i, int lastNumIdx, vector<vector<int>> &dp) {
            
        if(i==nums.size()) {
            return 0;
        }
        if(dp[i][lastNumIdx+1] != -1) {
            return dp[i][lastNumIdx+1];
        }
        int maxi = 0;
        if(lastNumIdx == -1 || nums[lastNumIdx] < nums[i]) {
            maxi = 1 + max(maxi, memo(nums, i+1, i, dp));
        }
        maxi = max(maxi, memo(nums,i+1, lastNumIdx, dp));
        return dp[i][lastNumIdx+1] = maxi;
    }
    
    int tab(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n+1, 1);

        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i] , dp[j]+1);
                }
            }
        }
        int maxi = 1;
        for(int i=0;i<n;i++) {
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return tab(nums);
    }
};

int main(){
    Solution s;
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << s.lengthOfLIS(nums) << endl;
}
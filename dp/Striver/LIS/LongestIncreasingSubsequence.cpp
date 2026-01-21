#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void powerSetRecursive(
        vector<int>& nums, 
        int i, 
        vector<vector<int>> &ans, 
        vector<int> &temp) {

        if(i==nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        powerSetRecursive(nums, i+1, ans, temp);
        temp.pop_back();
        powerSetRecursive(nums,i+1, ans, temp);
    }
    void powerSet(vector<int>& nums) {
        vector<vector<int>> num;
        num.push_back({});

        int n = nums.size();
        for(int i=0;i<n;i++) {
            int curr = nums[i];
            int sz = num.size();
            for(int j=0;j<sz;j++) {
                auto subSet = num[j];
                subSet.push_back(curr);
                num.push_back(subSet);
            }            
        }
    }
    int bruteForce(vector<int>& nums) {
        vector<vector<int>> num;
        num.push_back({});

        int n = nums.size();
        for(int i=0;i<n;i++) {
            int curr = nums[i];
            int sz = num.size();
            for(int j=0;j<sz;j++) {
                auto subSet = num[j];
                if(subSet.empty() || subSet.back() < curr) {
                    subSet.push_back(curr);
                    num.push_back(subSet);
                }
            }            
        }
        int ans = 0;
        for (auto& s : num) {
            ans = max(ans, (int)s.size());
        }
        return ans;
    }
    int bruteForceRecursive(
        vector<int>& nums, 
        int i, 
        vector<int> &temp) {
            
        if(i==nums.size()) {
            return temp.size();
        }
        int maxi = 0;
        if(temp.empty() || temp.back() < nums[i]) {
            temp.push_back(nums[i]);
            maxi = max(maxi, bruteForceRecursive(nums, i+1, temp));
            temp.pop_back();
        }
        maxi = max(maxi, bruteForceRecursive(nums,i+1, temp));
        return maxi;
    }
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
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--) {
            for(int j=i-1;j>= -1;j--) {
                int maxi = 0;
                if(j==-1 || nums[j] < nums[i]) {
                    maxi = 1 + max(maxi, dp[i+1][i+1]);
                }
                maxi = max(maxi, dp[i+1][j+1]);
                dp[i][j+1] = maxi;
            }
        }
        return dp[0][0];
        
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return memo(nums,0,-1,dp);
    }
};

int main(){
    Solution s;
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << s.lengthOfLIS(nums) << endl;
}
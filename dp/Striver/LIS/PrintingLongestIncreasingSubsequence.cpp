#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int tab(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n+1, 1);

        for(int i=0;i<n;i++) {
            for(int j=i-1;j>=0;j--) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i] , dp[j]+1);
                }
            }
        }
        int maxi = 1;
        for(int i=0;i<n;i++) {
            cout << dp[i] << " ";
            maxi = max(maxi, dp[i]);
        }
        cout << endl;
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
    vector<int> nums = {1, 5, 2, 3, 4};
    cout << s.lengthOfLIS(nums) << endl;
}
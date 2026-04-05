class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        if(n%2 == 1) {
            for(int i=1;i<n-1;i+=2) {
                long long maxi = max(nums[i-1], nums[i+1]);
                if(nums[i] <= maxi) {
                    ans += maxi - nums[i] + 1;
                }
            }
        } else {
            vector<int> dp(n+1);

            for(int i=1;i<n-1;i++) {
                long long maxi = max(nums[i-1], nums[i+1]);
                int sub = 0;
                if(nums[i] <= maxi) {
                    sub = maxi - nums[i] + 1;
                }
                if(i==1) {
                    dp[i] = sub;
                } else {
                    dp[i] = min(dp[i-2],dp[i-3]) + sub;
                }
            }
            return min(dp[n],dp[n-1]);
        }
        return ans;
    }
};
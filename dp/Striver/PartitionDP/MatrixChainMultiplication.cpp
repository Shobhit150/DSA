#include<iostream>
#include<vector>
#include <climits>
using namespace std;
class Solution {
public:
    int bruteForce(vector<int>& nums, int i, int j) {
        if(i==j) return 0;

        int ans = INT_MAX;

        for(int k=i;k<j;k++) {
            int cost = bruteForce(nums, i, k) +
                        bruteForce(nums, k+1, j) +
                        nums[i-1] * nums[k] * nums[j];
            ans = min(cost, ans);
        }

        return ans;

    }
    int memo(vector<int>& nums, int i, int j, vector<vector<int>> &dp) {
        if(i==j) return 0;
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = INT_MAX;

        for(int k=i;k<j;k++) {
            int cost = memo(nums, i, k, dp) +
                        memo(nums, k+1, j, dp) +
                        nums[i-1] * nums[k] * nums[j];
            ans = min(cost, ans);
        }

        return dp[i][j] = ans;
    }

    int tab(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i=n-1;i>=1;i--) {
            for(int j=i+1;j<n;j++) {
                int ans = INT_MAX;

                for(int k=i;k<j;k++) {
                    int cost = dp[i][k] +
                                dp[k+1][j] +
                                nums[i-1] * nums[k] * nums[j];
                    ans = min(cost, ans);
                }
                dp[i][j] = ans;
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return -1;
    }
    int matrixMultiplication(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return tab(nums);
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << s.matrixMultiplication(nums) << endl;
}
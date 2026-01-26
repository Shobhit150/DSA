#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    
    int tab(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n+1, 1);
        vector<int> cut(n+1, 1);
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(arr[j] < arr[i]) {
                    if(dp[j] + 1 == dp[i]) {
                        cut[i] += cut[j];
                    } else if(dp[i] < dp[j] + 1) {
                        dp[i] = dp[j]+1;
                        cut[i] = cut[j];
                    }
                }
            }
        }
        int maxi = 0;
        for(int i=0;i<n;i++) {
            maxi = max(maxi, dp[i]);
        }
        for(int i=0;i<n;i++) {
            maxi = max(maxi, dp[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(dp[i] == maxi) {
                ans += cut[i];
            }
        }
        return ans;
    }
    int findNumberOfLIS(vector<int> arr) {
        int n = arr.size();
        int res = tab(arr);
        
        return res;


    }
};

int main(){
    Solution s;
    vector<int> nums = {3,1,2};
    
    
    cout << s.findNumberOfLIS(nums);
    
}
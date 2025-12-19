#include<iostream>
using namespace std;
#define ll long long
class Solution {
public:
   
    int memo(vector<int>& prices, int i, int n, vector<int>&dp) {
        if(i==0) return dp[0] = 1;
        if(dp[i] != -1) return dp[i];
        if(prices[i]+1 == prices[i-1]) {
            dp[i] =  1 + memo(prices, i-1, n, dp);
        }else {
            dp[i] = 1;
        }
        return dp[i];
    }
    int tab(vector<int>& prices, int n) {
        vector<int> dp(n+1, 1);

        for(int i=1;i<n;i++) {
            cout << dp[i]+1 << " " << dp[i-1] << endl;
            if(prices[i]+1 == prices[i-1]) {
                dp[i] = 1 + dp[i-1];
            } 
        
        }
        ll ans = 0;
        for(int i=0;i<n;i++) {
            ans += dp[i];
        }
        return ans;

    }
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        ll ans = 0;
       

        vector<int> dp(n+1, -1);
        for(int i=0;i<n;i++) {
            ans += memo(prices, i, n, dp);
        }
        tab(prices, n);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> prices = {3,2,1,4};
    cout << s.getDescentPeriods(prices);
}
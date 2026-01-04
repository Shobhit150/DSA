
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

#define ll long long
class Solution {
public:
    int numOfWays(int n) {
        int MOD = 1e9 + 7;
        vector<vector<long long>> dp(n+1, vector<long long>(2,0));
        dp[1][0] = 6; // same
        dp[1][1] = 6; // different
       
        for(int i=2;i<=n;i++) {
            dp[i][0] = (dp[i-1][0]*2 + dp[i-1][1]*2)%MOD;
            //             diff*3 + same*2
            dp[i][1] = (dp[i-1][0]*2 + dp[i-1][1]*3)%MOD;
            // cout << dp[i][0] << " " << dp[i][1] << endl;

        }
        return (dp[n][0] + dp[n][1])%MOD;
    }
    
};
int main() {
    Solution s;
    int n=5000;
    cout << s.numOfWays(n);
}
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:

    int bruteForce(vector<int>& prices, int i, bool canBuy, bool justSold) {
        if(i==prices.size()) {
            return 0;
        }
        if(canBuy) { // 0
            if(!justSold) { // 1
                return max(-prices[i] + bruteForce(prices, i+1, false, false), bruteForce(prices, i+1, true, false));
            } else {
                return bruteForce(prices, i+1, true, false);
            }
        }
        return max(prices[i] + bruteForce(prices, i+1, true, true), bruteForce(prices, i+1, false, false));
    }
    int tab(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2,vector<int>(2,0)));
        for(int i=n-1;i>=0;i--) {
            dp[i][0][1] = max(-prices[i] + dp[i+1][1][1], dp[i+1][0][1]);
            dp[i][0][0] = dp[i+1][0][1];
            dp[i][1][0] = dp[i][1][1] = max(prices[i] + dp[i+1][0][0], dp[i+1][1][1]);
        }
        return dp[0][0][1];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        return tab(prices);
        

    }

    
    
};

int main() {
	Solution s;
    
	vector<int> prices = {1,2,3,0,2};
    
   
	cout << s.maxProfit(prices);
}

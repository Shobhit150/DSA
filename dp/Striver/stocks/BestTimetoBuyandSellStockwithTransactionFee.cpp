#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:

    int bruteForce(vector<int>& prices, int i, bool canBuy, int fees) {
        if(i==prices.size()) {
            return 0;
        }
        if(canBuy) { // 0
            return max(-prices[i] + bruteForce(prices, i+1, false, fees), bruteForce(prices, i+1, true, fees));
        }
        return max(prices[i] - fees + bruteForce(prices, i+1, true, fees), bruteForce(prices, i+1, false, fees));
    }
    int tab(vector<int>& prices, int fees) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        for(int i=n-1;i>=0;i--) {
            dp[i][0] = max(-prices[i] + dp[i+1][1], dp[i+1][0]);
            dp[i][1] = max(prices[i] - fees + dp[i+1][0], dp[i+1][1]);
        }
        return dp[0][0];
    }
    int maxProfit(vector<int>& prices, int fees) {
        int n = prices.size();

        
        return tab(prices,fees);
        

    }

    
    
};

int main() {
	Solution s;
    
	vector<int> prices = {1,3,2,8,4,9};
    int fees = 2;
    
   
	cout << s.maxProfit(prices, fees);
}

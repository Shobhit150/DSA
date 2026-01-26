#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    
    void tab(vector<int>& arr, vector<int> &dp) {
        
        int n = arr.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(arr[j] < arr[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
    }
    int LongestBitonicSequence(vector<int> arr) {
        int n = arr.size();

        vector<int> dp1(n+1,1);
        vector<int> dp2(n+1,1);
        tab(arr, dp1);
        reverse(arr.begin(), arr.end());
        tab(arr, dp2);
        int maxi = 0;

        for(int i=0;i<n;i++) {
            maxi = max(maxi, dp1[i] + dp2[n-i-1] - 1);
        }
        return maxi;


    }
};

int main(){
    Solution s;
    vector<int> arr = {10, 20, 30, 40, 50, 40, 30, 20};
    
    
    cout << s.LongestBitonicSequence(arr);
    
}
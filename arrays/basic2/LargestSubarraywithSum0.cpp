#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        vector<int> pre;
        int preSum = 0;
        int n = arr.size();
        unordered_map<int,int> mp;
        mp[0] = -1;
        int maxi = -1;

        for(int i=0;i<n;i++) {
            preSum += arr[i];
            pre.push_back(preSum);
            if(mp.find(preSum) != mp.end()) {
                maxi = max(maxi, i - mp[preSum]);
            } else {
                mp[preSum] = i;
            }
        }

        
        return maxi;
    }
};

int main() {
    Solution s;
    vector<int> arr = { 15, -2, 2, -8, 1, 7, 10, 23 };
    cout << s.maxLen(arr) << endl; 
}
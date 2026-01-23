#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int tab(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp = {nums[0]};
        
        for(int i=1;i<n;i++) {
            int num = nums[i];
            int l = 0;
            int r = dp.size();
            while(l < r) {
                int mid = (r+l)/2;
                if(dp[mid] < num) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            if(l == dp.size()) {
                dp.push_back(num);
            } else {
                dp[l] = num;
            }
        }
        return dp.size();
    }
    int tab2(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp = {nums[0]};
        
        for(int i=1;i<n;i++) {
            int num = nums[i];
            auto it = lower_bound(dp.begin(), dp.end(), num);
            if(it == dp.end()) {
                dp.push_back(num);
            } else {
                *it = num;
            }
        }
        return dp.size();
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        vector<int> dp(n+1, 1);
        return tab2(nums);
    }
};

int main(){
    Solution s;
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << s.lengthOfLIS(nums) << endl;
}
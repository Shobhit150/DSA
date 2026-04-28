#include<iostream>
#include<vector>
#include <algorithm>
#include<climits>
using namespace std;
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;
        vector<int> res;
        for(int i=n-1;i>=0;i--) {
            if(nums[i] > maxi) {
                res.push_back(nums[i]);
                maxi = nums[i];
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = { 1, 2, 5, 3, 1, 2 };
    vector<int> res = s.leaders(nums);
    for(int i=0;i<res.size();i++) {
        cout << res[i] << " ";
    }
}
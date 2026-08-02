#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    void recur(vector<int> &nums, int sumi, int i, vector<int> &ans) {
        if(i==nums.size()) {
            ans.push_back(sumi);
            return;
        }

        recur(nums, sumi + nums[i], i+1, ans);
        recur(nums, sumi, i+1, ans);
    }
    vector<int> subsetSums(vector<int>& nums) {
        vector<int> ans;
        recur(nums,0,0,ans);
        return ans;
    }
};

class Solution2 {
  public:
    void recur(vector<int> &arr, int i, vector<int> &curr, vector<vector<int>> &ans) {
        if(i==arr.size()) {
            ans.push_back(curr);
            return;
        }
        
        recur(arr,i+1,curr,ans);
        curr.push_back(arr[i]);
        recur(arr,i+1,curr,ans);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        // code here
        vector<vector<int>> ans;
        vector<int> curr;
        recur(arr,0,curr,ans);
        return ans;
    }
};

void solve() {
    
}

int main() {

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
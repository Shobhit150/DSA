#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int recur(vector<int> &nums, int target, int sumi, int i) {
        if(sumi == target) return 1;
        if(sumi > target) return 0;
        if(i==nums.size()) return 0;
        if(sumi + nums[i] > target) return 0;

        int tot = 0;
        tot += recur(nums, target, sumi + nums[i], i+1);
        tot += recur(nums, target, sumi, i+1);
        return tot;
    }
    int numSubseq(vector<int>& nums, int target) {
        
        return recur(nums, target, 0, 0);
    }
};

class Solution {
public:
    int recur(vector<int> &nums, int target, int sumi, int i) {
        if(sumi == target) return 1;
        if(sumi > target) return 0;
        if(i==nums.size()) return 0;
        if(sumi + nums[i] > target) return 0;

        int tot = 0;
        tot += recur(nums, target, sumi + nums[i], i+1);
        tot += recur(nums, target, sumi, i+1);
        return tot;
    }
    int countSubsequenceWithTargetSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return recur(nums, k, 0, 0);
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
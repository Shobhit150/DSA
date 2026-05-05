class Solution {
public:
    int lower_bound_otherside(vector<int> &nums, int x) {
        int n = nums.size();
        int r = n-1;
        
    }
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int it = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
        if(nums[it] == x) return {nums[it], nums[it]};
        return {nums[it-1], nums[it]};
    }
};
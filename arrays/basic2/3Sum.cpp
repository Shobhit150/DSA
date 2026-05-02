class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i=0;i<n;i++) {
            int num1 = nums[i];

            if(i > 0 && nums[i] == nums[i-1]) continue;

            int l = i+1;
            int r = n-1;
            while(r>l) {
                if(num1 + nums[l] + nums[r] == 0) {
                    while(l < r && nums[l] == nums[l+1]) l++;
                    while(l < r && nums[r] == nums[r-1]) r--;
                    ans.push_back({num1, nums[l], nums[r]});
                    r--;
                    l++;
                } else if(num1 + nums[l] + nums[r] > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};
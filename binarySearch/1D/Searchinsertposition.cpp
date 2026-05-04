class Solution {
public:
    int lower_bound2(vector<int> &nums, int x) {
        int n = nums.size();
        int l = 0;
        int r = n;
        while(l>r) {
            int mid = (r+l)/2;
            if(nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    int searchInsert(vector<int> &nums, int target)  {
       int idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
       return idx;
    }
};
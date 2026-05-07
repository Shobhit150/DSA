class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int miniNum = INT_MAX;
        int miniIdx = -1;
        while(l <= r) {
            int mid = (r+l)/2;
            if(nums[l] <= nums[mid]) {
                if(nums[l] < miniNum) {
                    miniIdx = l;
                    miniNum = nums[l];
                }
                l = mid+1;
            } else {
                if(nums[mid] < miniNum) {
                    miniIdx = mid;
                    miniNum = nums[mid];
                }
                r = mid-1;
            }
        }
        return miniIdx;
    }
};
class Solution{
public:
    int lowerBound(vector<int> &nums, int x){
        int n = nums.size();
        int l = 0;
        int r = n;

        while(l<r) {
            int mid = (l+r)/2;
            if(nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    int lowerBound2(vector<int> &nums, int x){
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int ans = n;

        while(l<=r) {
            int mid = (l+r)/2;
            if(nums[mid] >= x) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    int upperBound(vector<int> &nums, int x) {
        int n = nums.size();
        int l = 0;
        int r = n;
        while(l<r) {
            int mid = (l+r)/2;
            if(nums[mid] > x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    int upperBound2(vector<int> &nums, int x) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int ans = n;

        while(l<=r) {

            int mid = (l+r)/2;
            if(nums[mid] > x) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    

};
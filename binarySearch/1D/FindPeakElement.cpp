#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:

    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int r = n-1;

        if(n==1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[r] > nums[r-1]) return r;

        l = 1;
        r = r-1;
        while(l<=r) {
            int mid = (r+l)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                return mid;
            } else if(nums[mid] < nums[mid+1]) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return -1;
    }
};

void solve() {
    Solution s;
    vector<int> nums = {1,2,3,1};
    s.findPeakElement(nums);

}

int main() {

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
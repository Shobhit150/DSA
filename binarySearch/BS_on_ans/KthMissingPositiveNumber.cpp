#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        int l = 0;
        int r = n - 1;
        int ans = 0;
        while(l<=r) {
            int mid = (l+r)/2;
            int left_num =  arr[mid] - (mid+1);
            if(left_num < k) {
                ans = mid + 1;
                l = mid + 1;
            } else  {
                r = mid - 1;
            }
        }
        return ans + k;
    }
};

void solve() {
    vector<int> arr = {2,3,4,7,11};
    Solution s;
    s.findKthPositive(arr, 5);
}

int main() {

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
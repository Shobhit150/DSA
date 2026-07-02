#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); // [2,6,9,11]
                              //  0 1 2 3  
        int m = nums2.size(); // [1,5,10]

        if(m<n) return findMedianSortedArrays(nums2, nums1);

        int l = 0;
        int r = n;

        int leftSize = (n + m + 1) / 2;

        while(l<=r) {
            int parititon1 = (l+r)/2;
            int parititon2 = leftSize - parititon1;

            int l1 = (parititon1 == 0) ? INT_MIN : nums1[parititon1-1];
            int r1 = (parititon1 == n) ? INT_MAX : nums1[parititon1];
            int l2 = (parititon2 == 0) ? INT_MIN : nums2[parititon2-1];
            int r2 = (parititon2 == m) ? INT_MAX : nums2[parititon2];

            if(l1 <= r2 && l2 <= r1) {
                if((n+m)%2 == 0) {
                    return (max(l1,l2) + min(r1,r2))/2.0;
                }
                return max(l1,l2);
            }
            else if(l1 > r2) {
                r = parititon1 - 1;
            }
            else {
                l = parititon1 + 1;
            }
        }
        return -1;
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
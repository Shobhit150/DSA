#include <iostream>
#include <vector>
#include <climits>
using namespace std;


//  a = [2, 3, 6, 7, 9], b = [1, 4, 8, 10], k = 5
class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
        int m = a.size(); // a = [2, 3, 6,  7, 9]
                    //                    |
        int n = b.size(); // b = [1, 4,  8, 10]
                    //                 | 

        if(m>n) return kthElement(b,a,k);

        int l = 0; // 0
        int r = min(k,m); // 4

        while(l<=r) {
            int part1 = (l+r)/2; // 2
            int part2 = k - part1; // 3

            int l1 = (part1 == 0) ? INT_MIN : a[part1-1]; // 
            int r1 = (part1 == m) ? INT_MAX : a[part1];
            int l2 = (part2 == 0) ? INT_MIN : b[part2-1];
            int r2 = (part2 == n) ? INT_MAX : b[part2];

            if(l1 <= r2 && l2 <= r1) {
                return max(l1,l2);
            } else if(l1 > r2) {
                r = part1 - 1;
            } else {
                l = part1 + 1;
            }
        }
        return -1;
    }
};

void solve() {
    Solution s;
    vector<int> a = {1,2};
    vector<int> b = {3,4,5,6,7};
    int k = 5;
    s.kthElement(a,b,k);
}

int main() {

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
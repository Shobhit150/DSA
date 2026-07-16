#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    // int highest(vector<int> &num) {
    //     int l = 0;
    //     int n = num.size(); // n = 5
    //     int r = n-1; // 0 0 0 0 0

    //     int idx = lower_bound(num.begin(), num.end(), 1) - num.begin();
    //     return n - idx;
    // }
    // int rowWithMax1s(vector<vector<int>> & mat) {
    //     int m = mat.size();
    //     int n = mat[0].size();
    //     int maxi = 0;
    //     int idx = -1;
    //     int cnt = 0;
    //     for(auto &c: mat) {
    //         int curr = highest(c);
    //         if(curr > maxi) {
    //             maxi = curr;
    //             idx = cnt;
    //         }
    //         cnt++;
    //     }
    //     return idx;
    // }
    public:   
    int rowWithMax1s(vector<vector<int>> & mat) {
        int m = mat.size();
        int n = mat[0].size();

        int b = m - 1;
        int r = n - 1; // 0 0 1 1 1
                       // 0 1 2 3 4
        int ans = -1;
        int idx = -1;
        while(b>=0 && r>=0) {
            if(mat[b][r] == 1) {
                ans = max(ans, n - r);
                idx = b;
                r--;
            } else {
                b--;
            }
        }
        return idx;
    }
};

void solve() {
    Solution s;
    vector<vector<int>> nums = {{1,1,1},{0,0,1},{0,0,0}};
    s.rowWithMax1s(nums);
}

int main() {

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
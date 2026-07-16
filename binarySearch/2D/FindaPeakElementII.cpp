#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int l = 0;
        int r = n - 1;

        while(l<=r) {
            int mid = (l+r)/2;
            int maxi = mat[0][mid];
            int idx = 0;
            for(int i=1;i<m;i++) {
                if(mat[i][mid] > maxi) {
                    idx = i;
                    maxi = mat[i][mid];
                }
            }

            int left = (mid == 0) ? -1 : mat[idx][mid - 1];
            int right = (mid == n-1) ? -1 : mat[idx][mid + 1];

            if(maxi > left && maxi > right) {
                return {idx, mid};
            } else if(maxi < left) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return {-1,-1};
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
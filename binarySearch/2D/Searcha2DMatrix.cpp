#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0;
        int r = m*n - 1;
        while(l<=r) {
            int mid = (l+r)/2;
            int row = mid/m;
            int col = mid%m;

            if(target == matrix[row][col]) {
                return true;
            } else if(target > matrix[row][col]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return true;
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
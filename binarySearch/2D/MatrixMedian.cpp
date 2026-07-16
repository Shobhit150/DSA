#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int findLess(vector<vector<int>>&matrix, int mid, int m) {
        int sumi = 0;
        for(int i=0;i<m;i++) {
            sumi += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        return sumi;
    }
    int findMedian(vector<vector<int>>&matrix) {
        int low = INT_MAX;
        int high = INT_MIN;
        int m = matrix.size();
        int n = matrix[0].size();

        int half = (m*n)/2;

        for(int i=0;i<m;i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][n-1]);
        }
        int ans = -1;

        while(low<=high) {
            int mid = (low+high)/2;

            int lessThanEquals = findLess(matrix, mid, m);

            if(lessThanEquals > half) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
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
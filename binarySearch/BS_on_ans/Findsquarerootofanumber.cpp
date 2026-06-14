#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int floorSqrt(int n)  {
      int l = 0;
      int r = n;
      int ans = -1;
      while(l<=r) {
        int mid = (l+r)/2;
        if(mid * mid <= n) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
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
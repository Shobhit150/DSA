#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool isPowerofTwo(int n) {
        return n>0 && (n && (n-1))==0;
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
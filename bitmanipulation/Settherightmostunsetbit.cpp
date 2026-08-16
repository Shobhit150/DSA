#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int setBit(int n) {
        int n1 = ~n; // 00001111
        n1 = n1 & (-n1);
        n |= n1;
        return n;
        // 11110000
        // 11101111
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
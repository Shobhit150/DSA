#include <iostream>
#include <vector>
using namespace std;

// 1 0001
// 3     0001 ^ 0010
// 0    0001 ^ 0010 ^ 0011
class Solution {
  public:
    int xorOneToN(int n) {
        if(n%4 == 1) return 1;
        if(n%4 == 2) return n+1;
        if(n%4 == 3) return 0;
        return n;
    }
    int findXOR(int l, int r) {
        return xorOneToN(l-1) ^ xorOneToN(r);
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
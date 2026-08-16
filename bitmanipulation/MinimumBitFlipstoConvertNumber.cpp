#include <iostream>
#include <vector>
#include<bit>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal;
        return __builtin_popcount(x);
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
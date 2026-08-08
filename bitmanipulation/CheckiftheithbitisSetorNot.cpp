#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkIthBit(int n, int i) {
        return (n>>i) & 1;

        // return (n)&(1<<i)
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
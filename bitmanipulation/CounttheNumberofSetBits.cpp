#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int setBits(int n) {
        int cnt = 0;
        while(n) {
            n &= (n-1);
            cnt++;
        }
        return cnt;
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
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool isEven(int n) {
        return !(n & 1);
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
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        int ans = 0;
        while(a >= b) {
            int mul = 1;
            long long curr = b;
            while((curr << 1) <= a) {
                mul <<= 1;
                curr <<= 1;
            }

            a -= curr;
            ans += mul;
        }
        if ((dividend < 0) ^ (divisor < 0))
            ans = -ans;
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
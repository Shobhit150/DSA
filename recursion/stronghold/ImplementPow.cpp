#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    double helper(double b, long long e, double res) {
        if(e == 0) return (double)res;

        if(e%2 == 1) {
            res = res*b;
            e--;
        }

        return helper(b*b, e/2, res);
    }
    double power(double b, int e) {
        long long e1 = e;
        if(e<0) {
            e1 = e1*-1;
            b = 1/b;
        }
        return helper(b,e1,1);
    }
};

void solve() {
    Solution s;
    double x = 2.00000;
    int n = -2;
    s.power(x,-2);
}

int main() {

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
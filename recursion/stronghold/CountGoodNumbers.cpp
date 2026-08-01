#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int fastExpo(long long a, long long b, int mod) {
        long long res = 1;
        while(b) {
            if(b%2 == 1) {
                res = (res * a)%mod;
            } 
            a = (a * a)%mod;
            b >>= 1;
        }
        return res > INT_MAX ? INT_MAX : res;
    }
    int countGoodNumbers(long long n) {
        long long b = n/2;
        long long a = (n+1)/2;
        int mod = 1e9 + 7;
        int ans = (1LL * fastExpo(5,a,mod) * fastExpo(4,b,mod))%mod;
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
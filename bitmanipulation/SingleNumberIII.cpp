#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x = 0;
        for(int &a: nums) {
            x ^= a;
        }

        x = x & -x;
        int a = 0;
        int b = 0;
        for(int &num: nums) {
            if((long long)num & x) {
                a ^= num;
            } else {
                b ^= num;
            }
        }
        return {a,b};

        // 1101100
        // 0010100 -n

        // 1101011 n-1
        // 0010100 ~(n-1)
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
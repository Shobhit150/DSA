#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int exponential(int a, int b) {
        int res = 1;
        while(b) {
            if(b%2 == 1) {
                res = res * a;
                b--;
            } else {
                b = b >> 1;
                a = a * a;
            }
        }
        return res;
    }
    int NthRoot(int N, int M) {
        int l = 0;
        int r = M;
        int ans = -1;
        while(l<=r) {
            int mid = (l+r)/2;
            int val = exponential(mid, N);
            if(val == M) {
                return mid;
            } else if(val < M) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return -1;
    }
};

void solve()
{
}

int main()
{

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
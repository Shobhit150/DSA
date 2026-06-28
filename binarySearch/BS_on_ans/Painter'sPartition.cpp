#include <iostream>
#include <vector>
using namespace std;

// Painter's Partition
// Subscribe to TUF+

// Hints
// Company
// You are given A painters and an array C of N integers where C[i] denotes the length of the ith board. Each painter takes B units of time to paint 1 unit of board. You must assign boards to painters such that:

// Each painter paints only contiguous segments of boards.
// No board can be split between painters.
// The goal is to minimize the time to paint all boards.


// Return the minimum time required to paint all boards modulo 10000003.


// Example 1

// Input: A = 2, B = 5, C = [1, 10]

// Output: 50

// Explanation:

// Painter 1 paints board 0 (length = 1), time = 5
// Painter 2 paints board 1 (length = 10), time = 50
// Max time = 50
// Return 50 % 10000003 = 50

class Solution {
public:
    int MOD = 10000003;
    bool check(vector<int> &C, int mid, int A) {
        int n = C.size();
        int sumi = 0;
        int cnt = 1;
        for(int i=0;i<n;i++) {
            if(sumi + C[i] > mid) {
                sumi = 0;
                cnt++;
            }
            sumi += C[i];
        }
        return cnt <= A;
    }
    int paint(int A, int B, vector<int>& C) {
        int l = 0;
        int r = 0;
        int n = C.size();
        for(int i=0;i<n;i++) {
            l = max(l, C[i]);
            r += C[i];
        }
        int ans = -1;

        while(l<=r) {
            int mid = (l+r)/2;
            if(check(C, mid, A)) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid +1;
            }
        }
        return 1LL * ans*B %MOD;
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
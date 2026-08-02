#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool recur(vector<int> &arr, int k, int i, int sumi) {
        if(sumi == k) return true;
        if(i==arr.size()) return false;
        if(sumi > k) return false;

        if(recur(arr, k, i+1, sumi + arr[i])) return true;
        if(recur(arr, k, i+1, sumi)) return true;

        return false;
    }
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        return recur(arr, k, 0, 0);
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
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void recur(int k, int n, int i, vector<int> &curr, vector<vector<int>> &ans) {
        if(n == 0 && k==0) {
            ans.push_back(curr);
            return;
        }
        if(i==10) {
            return;
        }
        if(n < 0) return;
        if(k==0) return;

        curr.push_back(i);
        recur(k - 1, n - i, i+1, curr, ans);
        curr.pop_back();
        recur(k, n, i+1, curr, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> ans;
        recur(k,n,1,curr,ans);
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
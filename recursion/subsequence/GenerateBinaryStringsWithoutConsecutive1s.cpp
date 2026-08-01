#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void recursion(int n, string curr, vector<string> &ans) {
        if (curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        if (curr.empty() || curr.back() != '0')
            recursion(n, curr + '0', ans);

        recursion(n, curr + '1', ans);
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        recursion(n, "", ans);
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
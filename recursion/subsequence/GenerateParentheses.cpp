#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    void recur(int n, string curr, vector<string> &ans, int o, int c) {
        if(curr.size()==2*n) {
            ans.push_back(curr);
            return;
        }

        if(o<n) {
            recur(n,curr + '(', ans, o+1, c);
        }

        if(c<n && o>c) {
            recur(n,curr + ')', ans, o, c+1);
        }
    }
    vector<string> generateParentheses(int n) {
        vector<string> ans;
        recur(n,"",ans,0,0);
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
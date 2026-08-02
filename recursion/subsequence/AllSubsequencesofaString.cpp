#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    void recur(string &s, string curr, int i, vector<string> &ans) {
        if(i==-1) {
            ans.push_back(curr);
            return;
        }
        
        
        recur(s,curr, i-1,ans);
        
        recur(s,s[i]+curr, i-1,ans);
    }
    vector<string> powerSet(string &s) {
        vector<string> ans;
        int n = s.size();
        recur(s, "", n-1, ans);
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
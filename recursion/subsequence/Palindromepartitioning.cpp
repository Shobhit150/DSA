#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(string &s, int st, int en) {
        while(en>st) {
            if(s[st] != s[en]) return false;
            st++;
            en--;
        }
        return true;
    }
    void recur(string &s, int idx, vector<string> &curr, vector<vector<string>> &ans) {
        if(idx == s.size()) {
            ans.push_back(curr);
            return;
        }

        for(int i=idx;i<s.size();i++) {
            if(isPalindrome(s,idx, i)) {
                curr.push_back(s.substr(idx,i-idx+1));
                recur(s, i+1, curr, ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> ans;
        recur(s,0,curr,ans);
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
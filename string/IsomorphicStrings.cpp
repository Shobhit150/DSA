#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> s1(256,-1);
        vector<int> t1(256,-1);

        for(int i=0;i<s.size();i++) {
            if(t1[t[i]] == -1 && s1[s[i]] == -1) {
                s1[s[i]] = t[i];
                t1[t[i]] = s[i];
            } else if(t1[t[i]] != s[i] || s1[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
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
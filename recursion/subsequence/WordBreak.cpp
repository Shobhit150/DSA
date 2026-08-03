#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool recur(string &s, vector<string>& wordDict, int i, vector<int> &mem) {
        if(i > s.size()) return false;
        if(i==s.size()) return true;
        if(mem[i] != -1) {
            if(mem[i] == 0) return false;
            return true;
        }
        for(int k=0;k<wordDict.size();k++) {
            if(s.substr(i, wordDict[k].size()) == wordDict[k]) {
                if(recur(s, wordDict, i+wordDict[k].size(),mem)) {
                    mem[i] = 1;
                    return true;
                };
            }
        }
        mem[i] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> mem(s.size()+1,-1);
        return recur(s,wordDict,0, mem);
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
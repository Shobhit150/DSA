#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        string ans = "";

        for(int j=0;j<strs[0].size();j++) {
            int m = strs[0].size();
            char c = strs[0][j];
            for(int i=1;i<n;i++) {
                if(j==strs[i].size()) {
                    return ans;
                }
                if(strs[i][j] != c) {
                    return ans;
                }
            }
            ans.push_back(c);
        }
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
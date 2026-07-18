#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<char> st;
        string ans = "";
        for(char &c: s) {
            if(c=='(') {
                if(!st.empty()) {
                    ans.push_back('(');
                }
                st.push_back('(');
            } else {
                st.pop_back();
                if(!st.empty()) {
                    ans.push_back(')');
                }
            }
        }
        return ans;
    }
};

void solve() {
    Solution s;
    string s1 = "(()())(())";
    s.removeOuterParentheses(s1);
}

int main() {

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
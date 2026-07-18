#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        for(int i = 0; i < n; ) {

            while(i < n && s[i] == ' ')
                i++;

            int start = i;

            while(i < n && s[i] != ' ')
                i++;

            reverse(s.begin() + start, s.begin() + i);
        }

        reverse(s.begin(), s.end());
        return s;
    }
};

void solve() {
    Solution s;
    string s1 = "the sky is blue";
    s.reverseWords(s1);
}

int main() {

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
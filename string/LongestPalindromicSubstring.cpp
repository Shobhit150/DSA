#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void expand(string &s, int left, int right, int &maxi, string &ans) {
        int n = s.size();
        while(left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        int num = (right-left-1);

        if(num>maxi) {
            maxi = num;
            ans = s.substr(left+1, (right-left-1));
        }
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int maxi = 0;
        string ans = "";
        for(int i=0;i<n;i++) {
            expand(s,i,i,maxi, ans);
            if(i!=n-1) {
                expand(s,i,i+1,maxi, ans);
            }
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
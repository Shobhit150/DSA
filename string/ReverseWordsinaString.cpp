#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i=0;
        string temp;
        while(i<n) {
            while(i<n && s[i] == ' ') {
                i++;
            }
            while(i<n && s[i] != ' ') {
                temp += s[i];
                i++;
            }
            if(i<n) {
                temp += ' ';
            }
            
        }
        int start = 0;
        for(int i=0;i<=temp.size();i++) {
            
            if(i==temp.size() || temp[i] == ' ') {
                reverse(temp.begin() + start, temp.begin()+i);
                start = i + 1;
            }
        }
        reverse(temp.begin(), temp.end());

        return temp;
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
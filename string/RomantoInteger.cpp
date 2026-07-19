#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}      
        };
        int n = s.size();
        int tot = mp[s[n-1]];
        for(int i=n-2;i>=0;i--) {
            if(mp[s[i]] >= mp[s[i+1]]) {
                tot += mp[s[i]];
            } else {
                tot = tot - mp[s[i]];
            }
        }
        return tot;
    }
};

void solve() {
    Solution s;
    string s1 = "MCMXCIV";
    s.romanToInt(s1);
}

int main() {

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
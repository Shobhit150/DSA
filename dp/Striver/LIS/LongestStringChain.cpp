#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool comp(string& shorter,string& longer) {
        if(longer.size() - shorter.size() != 1) return false;
        int j=0;
        for(int i=0;i<longer.size();i++) {
            if(j < shorter.size() && longer[i] == shorter[j]) {
                j++;
            }
        }
        if(j==shorter.size()) return true;
        return false;
    }
    
    int tab(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &str1,string &str2) {
            return str1.size() < str2.size();
        });
        int n = words.size();
        int maxi = 1;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(comp(words[j],words[i])) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    maxi = max(maxi, dp[i]);
                }
            }
        }
        return maxi;
    }
    int longestStrChain(vector<string>& words) {
        return tab(words);
    }
};

int main(){
    Solution s;
    vector<string> words = {"a","b","ba","bca","bda","bdca"};
    string str1 = "bdca";
    string str2 = "bdc";
    
    cout << s.longestStrChain(words);
    
}
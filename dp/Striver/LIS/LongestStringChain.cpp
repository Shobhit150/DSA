#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool comp(string& str1, string& str2) {
        if(str2.size() - str1.size() != 1) return false;
        int j=0;
        for(int i=0;i<str2.size();i++) {
            if(str2[i] == str1[j]) {
                j++;
            }
        }
        if(j==str1.size()) return true;
        return false;
    }
    
    int tab(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &str1, string str2) {
            return str1.size() < str2.size();
        });
        int n = words.size();
        int maxi = 1;
        vector<int> dp(n+1,1);
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(comp(words[i],words[j])) {
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
    string str2 = "bd";
    
    cout << s.comp(str1, str2);
    
}
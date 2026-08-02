#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    void recur(vector<int> &arr, int i, unordered_map<int, string> &mp, string &curr, vector<string> &ans) {
        if(i==arr.size()) {
            ans.push_back(curr);
            return;
        }

        if (arr[i] == 0 || arr[i] == 1) {
            recur(arr, i + 1, mp, curr, ans);
            return;
        }
        string pos = mp[arr[i]];
        for(int j=0;j<pos.size();j++) {
            curr.push_back(pos[j]);
            recur(arr,i+1,mp,curr,ans);
            curr.pop_back();
        }
    }
    vector<string> possibleWords(vector<int> &arr) {
        unordered_map<int, string> mp = {
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"},
        };
        string curr = "";
        vector<string> ans;
        recur(arr,0,mp,curr,ans);
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
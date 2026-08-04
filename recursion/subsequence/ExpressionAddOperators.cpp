#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void recur(string num, int target, int idx, long long total, long long prevValue, string curr, vector<string> &ans) {
        if(idx == num.size()) {
            if(total == target) {
                ans.push_back(curr);
            }
            return;
        }

        long long currNum = 0;

        for(int i=idx;i<num.size();i++) {
            if (i > idx && num[idx] == '0')
                break;

            currNum = currNum * 10 + (num[i] - '0');
            string currStr = num.substr(idx, i - idx + 1);

            if(idx == 0) {
                recur(num,target,i+1,currNum,currNum,currStr,ans);
            } else {
                recur(num,target,i+1,total + currNum,currNum,curr+ "+"+currStr ,ans);
                recur(num,target,i+1,total - currNum,-currNum,curr+ "-"+currStr ,ans);
                recur(num,target,i+1,total - prevValue + (prevValue*currNum),prevValue*currNum,curr+ "*"+currStr ,ans);
            }
        }
    }
    vector<string> findExpr(string num, int target) {
        string curr = "";
        vector<string> ans;
        recur(num,target,0,0,0,curr,ans);
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
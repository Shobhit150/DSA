#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSafe(vector<string> &mat, int r, int c) {
        int n = mat.size();
        for(int i=0;i<r;i++) {
            if(mat[i][c] == 'Q') return false;
        }

        int i = r;
        int j = c;
        // top left
        while(i>=0 && j>=0) {
            if(mat[i][j] == 'Q') return false;
            i--;
            j--;
        }

        i = r;
        j = c;
        //top right
        while(i>=0 && j<n) {
            if(mat[i][j] == 'Q') return false;
            i--;
            j++;
        }
        return true;
    }

    void recur(int n, int r, vector<string> &curr, vector<vector<string>> &ans) {
        if(r == n) {
            ans.push_back(curr);
            return;
        }

        for(int i=0;i<n;i++) {
            if(isSafe(curr, r, i)) {
                curr[r][i] = 'Q';
                recur(n,r+1,curr,ans);
                curr[r][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> curr;
        vector<vector<string>> ans;
        string tmp = "";
        for(int i=0;i<n;i++) {
            tmp += '.';
        }
        for(int i=0;i<n;i++) {
            curr.push_back(tmp);
        }
        recur(n,0,curr,ans);
        return ans;
    }
};


class Solution2 {
public:
    bool isSafe(vector<int> &mat, int r, int c) {
        int n = mat.size();
        for(int i=0;i<r;i++) {
            if(mat[i] == c) return false;

            if(abs(mat[i] - c) == abs(i-r)) return false;
        }
        return true;
    }

    void recur(int n, int r, vector<int> &curr, vector<vector<int>> &ans) {
        if(r == n) {
            ans.push_back(curr);
            return;
        }

        for(int i=0;i<n;i++) {
            if(isSafe(curr, r, i)) {
                curr.push_back(i);
                recur(n,r+1,curr,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<int> curr;
        vector<vector<int>> ans;
        
        recur(n,0,curr,ans);
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
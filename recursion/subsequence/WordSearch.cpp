#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool recur(vector<vector<char>> &mat, string &word, int idx, int i, int j, int m, int n) {
        if(idx == word.size()) {
            return true;
        }

        if(i<0 || i==m || j<0 || j==n || mat[i][j] != word[idx]) {
            return false;
        }
        char c = mat[i][j];
        mat[i][j] = '#';
        if(recur(mat, word, idx+1, i+1,j,m,n)) return true;
        if(recur(mat, word, idx+1, i-1,j,m,n)) return true;
        if(recur(mat, word, idx+1, i,j+1,m,n)) return true;
        if(recur(mat, word, idx+1, i,j-1,m,n)) return true;
        mat[i][j] = c;
        return false;
    }
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(recur(mat,word, 0,i,j,m,n)) return true;
            }
        }
        return false;
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
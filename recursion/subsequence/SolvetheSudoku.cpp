#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    bool isSafe(int r, int c, int num, vector<vector<int>> &mat, vector<vector<int>> &box, vector<vector<int>> &col, vector<vector<int>> &row) {
        int boxNo = (r/3)*3 + (c/3);
        if(box[boxNo][num] != -1) return false;
        if(row[r][num] != -1) return false;
        if(col[c][num] != -1) return false;
        return true;
    }
    bool recur(int idx, vector<vector<int>> &mat, vector<vector<int>> &box, vector<vector<int>> &col, vector<vector<int>> &row) {
        if(idx==81) {
            return true;
        }
        int r = idx/9;
        int c = idx%9;
        if(mat[r][c] != 0)
            return recur(idx + 1, mat, box, col, row);
        for(int num=1;num<=9;num++) {
            if(isSafe(r,c,num,mat,box,col,row)) {
                int boxNo = (r/3)*3 + (c/3);
                box[boxNo][num] = 1;
                row[r][num] = 1;
                col[c][num] = 1;
                mat[r][c] = num;
                if(recur(idx+1,mat,box,col,row)) {
                    return true;
                }
                mat[r][c] = 0;
                box[boxNo][num] = -1;
                row[r][num] = -1;
                col[c][num] = -1;
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<int>> &mat) {
        vector<vector<int>> box(10, vector<int>(10,-1));
        vector<vector<int>> col(10, vector<int>(10,-1));
        vector<vector<int>> row(10, vector<int>(10,-1));
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(mat[i][j] != 0) {
                    int num = mat[i][j];
                    int b = (i/3) * 3 + (j/3);
                    row[i][num] = 1;
                    col[j][num] = 1;
                    box[b][num] = 1;
                }
            }
        }
        recur(0,mat,box,col,row);
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
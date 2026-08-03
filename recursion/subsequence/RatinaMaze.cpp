#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void recur(vector<vector<int>>& maze, int i, int j, int n, string curr, vector<string> &ans) {
        if(i==n-1 && j==n-1 && maze[i][j] == 1) {
            ans.push_back(curr);
            return;
        }
        if(i<0 || j < 0 || i==n || j==n || maze[i][j] != 1) {
            return;
        }
        maze[i][j] = -1;

        recur(maze, i+1, j, n, curr + 'D', ans);
        recur(maze, i, j-1, n, curr + 'L', ans);
        recur(maze, i, j+1, n, curr + 'R', ans);
        recur(maze, i-1, j, n, curr + 'U', ans);
        

        maze[i][j] = 1;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        int n = maze.size();
        recur(maze, 0,0,n,"",ans);
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
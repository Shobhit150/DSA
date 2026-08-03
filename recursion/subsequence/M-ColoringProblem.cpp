#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool isSafe(vector<vector<int>> &adj, vector<int>&colors,int color, int node) {
        for(int i=0;i<adj[node].size();i++) {
            if(colors[adj[node][i]] == color) return false;
        }
        return true;
    }
    bool recur(int v, vector<vector<int>> &adj, int idx, int m, vector<int> &colors) {
        if(idx==v) return true;

        for(int color=0;color<m;color++) {
            if(isSafe(adj, colors,color, idx)) {
                colors[idx] = color;
                if(recur(v,adj,idx+1,m,colors)) {
                    return true;
                }
                colors[idx] = -1;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<int> colors(v,-1);
        vector<vector<int>> adj(v);
        for(auto& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return recur(v,adj,0,m,colors);
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
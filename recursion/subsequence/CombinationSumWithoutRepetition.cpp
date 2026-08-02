#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void recur(vector<int> &arr, vector<int>&curr, int target, int i, int sumi, vector<vector<int>> &ans) {
        if(sumi ==target) {
            ans.push_back(curr);
            return;
        }
        if(sumi > target) return;
        if(i==arr.size()) return;

        for(int j=i;j<arr.size();j++) {
            if(i!=j && arr[j] == arr[j-1]) continue;
            curr.push_back(arr[j]);
            recur(arr, curr, target, j+1, sumi+ arr[j], ans);
            curr.pop_back();
        }
    }
    void recu2(vector<int> &arr, vector<int>&curr, int target, int i, int sumi, vector<vector<int>> &ans) {
        if(sumi ==target) {
            ans.push_back(curr);
            return;
        }
        if(sumi > target) return;
        if(i==arr.size()) return;
        curr.push_back(arr[i]);
        recu2(arr, curr, target, i+1, sumi + arr[i], ans);
        curr.pop_back();
        recu2(arr, curr, target, i+1, sumi, ans);
    }
    vector<vector<int>> uniqueCombinations(vector<int> &arr, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        recur(arr, curr, target, 0, 0, ans);
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
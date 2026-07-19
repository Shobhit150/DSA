#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        vector<int> vec;
        int maxi = 0;
        for(char &c: s) {
            if(c=='(') {
                vec.push_back('(');
            } else if(c==')') {

                vec.pop_back();
            }
            maxi = max(maxi, int(vec.size()));
        }
        return maxi;
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
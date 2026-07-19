#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) {
            return false;
        }
        string s1 = s + s;
        int n = s.size();

        for(int i=0;i<n;i++) {
            if(s1.substr(i,n) == goal) {
                return true;
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
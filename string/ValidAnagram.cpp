#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(256, 0);
        for(char &c: s) {
            freq[c]++;
        }

        for(char &c: t) {
            freq[c]--;
        }

        for(int i=0;i<256;i++) {
            if(freq[i] != 0) {
                return false;
            }
        }

        return true;
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
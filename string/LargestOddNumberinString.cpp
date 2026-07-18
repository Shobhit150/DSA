#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int br = -1;
        for(int i=n-1;i>=0;i--) {
            if((num[i]-'0')%2 == 1) {
                return num.substr(0,i+1);
            }
        }
        return "";
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
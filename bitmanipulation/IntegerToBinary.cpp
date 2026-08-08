#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

string intToBinary(int x) {
    string res = "";
    while(x) {
        if(x%2 == 1) res += '1';
        else res += '0';
        x >>= 1;
    }
    reverse(res.begin(), res.end());
    return res;
}

void solve() {
    cout << intToBinary(13);    
}

int main() {

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
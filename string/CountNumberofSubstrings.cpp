#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int atMostK(string &s, int k) {

    int n = s.size();
    int l = 0;
    int tot = 0;
    unordered_map<char, int> freq;
    for(int r=0;r<n;r++) {
        freq[s[r]]++;
        while(freq.size() > k) {
            freq[s[l]]--;
            if(freq[s[l]] == 0) freq.erase(s[l]);
            l++;
        }
        tot += (r-l+1);
    }
    return tot;
}

int countSubstrings(string s, int k) {
    return atMostK(s,k) - atMostK(s,k-1);
}

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
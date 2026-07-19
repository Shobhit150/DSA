#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,int>> pq;

        vector<int> freq(126,0);
        for(char &c: s) {
            freq[c]++;
        }

        for(int i=0;i<126;i++) {
            if(freq[i] > 0) {
                pq.push({freq[i], i});
            }
        }
        string ans = "";

        while(!pq.empty()) {
            string temp(pq.top().first, pq.top().second);
            ans += temp; 
            pq.pop();
        }
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
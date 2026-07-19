#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long long num = 0;
        int n = s.size();
        int i = 0;
        bool isPos = true;
        while(i<n && s[i]==' ') i++;

        if(i<n && s[i] == '+') i++;
        else if(s[i] == '-') {
            isPos = false;
            i++;
        } 
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            num = num * 10 + digit;

            if (isPos && num >= INT_MAX)
                return INT_MAX;
            if (!isPos && -num <= INT_MIN)
                return INT_MIN;

            i++;
        }
        return isPos ? num : -num;
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
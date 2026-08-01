#include <iostream>
#include <vector>
#include<climits>
using namespace std;

class Solution {
    public:
    int helper(string &s, int i, int sign, long long num) {
        if(i==s.size() || !isdigit(s[i])) {
            return (int)(num*sign);
        }
        num = 10*num + (s[i] - '0');

        if(num > INT_MAX && sign == 1) {
            return INT_MAX;
        }
        if(num > INT_MAX && sign == -1) {
            return INT_MIN;
        }

        return helper(s,i+1,sign,num);
    }
    int myAtoi(string &s) {
        int n = s.size();
        int i = 0;
        long long num = 0;
        while(i<n && s[i] == ' ') {
            i++;
        } 
        int sign = 1;
        if(i<n) {
            if(s[i] == '+') {
                i++;
            } else if(s[i] == '-') {
                sign = -1;
                i++;
            }
        }
        
        return helper(s, i, sign, num);
    }
};


void solve() {
    Solution s;
    string s1 = "-123";
    s.myAtoi(s1);
}

int main() {

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
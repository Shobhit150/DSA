#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void insert(stack<int> &st, int x) {
        if(st.empty()) {
            st.push(x);
            return;
        }

        int num = st.top();
        st.pop();

        insert(st, x);

        st.push(num);
    }
    void reverseStack(stack<int> &st) {
        if(st.empty()) {
            return;
        }

        int num = st.top();
        st.pop();

        reverseStack(st);

        insert(st, num);
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
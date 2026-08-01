#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sort2(stack<int> &st, int n, stack<int> &aux) {
        while(!st.empty() && st.top() <= n) {
            aux.push(st.top());
            st.pop();
        }
        st.push(n);
        while(!aux.empty()) {
            st.push(aux.top());
            aux.pop();
        }
    }
    void insert(stack<int> &st, int n) {
        if(st.empty() || st.top() < n) {
            st.push(n);
            return;
        }

        int num = st.top();
        st.pop();

        insert(st, n);

        st.push(num);
    }

    void sort(stack<int> &st) {
        if(st.empty()) return;

        int num = st.top();

        st.pop();

        sort(st);

        insert(st, num);
    }

    
    void sortStack(stack<int> &st) {

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
class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int,int> count;
        int limit = cbrt(n);
        for(int i=1;i<=limit;i++) {
            for(int b = i;b<=limit;b++) {
                int x = i*i*i + b*b*b;
                if(x>n) break;

                count[x]++;
            }
        }
        vector<int> ans;
        for(auto &p: count) {
            if(p.second >= 2) {
                ans.push_back(p.first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char,int> mp;
        for(char &c: s) {
            mp[c]++;
        }
        int ans = 0;
        unordered_set<char> visited;
        for(auto &p: mp) {
            char c = p.first;

            if(visited.count(c)) continue;
            char mirror;
            if(isalpha(c)) {
                mirror = 'z' - (c - 'a');
            } else {
                mirror = '9' - (c - '0');            
            }
            int f1 = mp[c];
            int f2 = mp.count(mirror) ? mp[mirror] : 0;
            ans += abs(f1 - f2);
            visited.insert(c);
            visited.insert(mirror);
        }
        return ans;
    }
};©leetcode
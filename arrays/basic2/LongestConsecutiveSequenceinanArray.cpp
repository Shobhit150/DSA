class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        // unordered_map<int,int> mp;
        int maxi = 0;
        for(int i=0;i<n;i++) {
            st.insert(nums[i]);
        }

        for(auto num: st) {
            if(st.find(num-1) == st.end()) {
                int count = 1;
                int curr = num;
                while(st.find(curr+1) != st.end()) {
                    count++;
                    curr++;
                }
                maxi = max(maxi, count);
            }
            
        }
        return maxi;
    }
};
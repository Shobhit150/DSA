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

        for(int i=0;i<n;i++) {
            int num = nums[i];
            int count = 1;
            while(st.find(num-1) != st.end()) {
                count++;
                num--;
            }
            maxi = max(maxi, count);
        }
        return maxi;
    }
};
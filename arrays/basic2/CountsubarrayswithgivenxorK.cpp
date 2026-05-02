class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int xr = 0;
        int count = 0;
        for(int i=0;i<n;i++) {
            xr ^= nums[i];
            int curr = k ^ xr;

            if(mp.find(curr) != mp.end()) {
                count += mp[curr];
            }
            mp[xr]++;
        }

        return count;
    }
};
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int recur(vector<int> &nums, int target, int sumi, int i) {
        if(sumi == target) return 1;
        if(sumi > target) return 0;
        if(i==nums.size()) return 0;
        if(sumi + nums[i] > target) return 0;

        int tot = 0;
        tot += recur(nums, target, sumi + nums[i], i+1);
        tot += recur(nums, target, sumi, i+1);
        return tot;
    }
    int numSubseq(vector<int>& nums, int target) {
        
        return recur(nums, target, 0, 0);
    }
};

class Solution3 {
public:
    int recur(vector<int> &nums, int target, int sumi, int i) {
        if(sumi == target) return 1;
        if(sumi > target) return 0;
        if(i==nums.size()) return 0;
        if(sumi + nums[i] > target) return 0;

        int tot = 0;
        tot += recur(nums, target, sumi + nums[i], i+1);
        tot += recur(nums, target, sumi, i+1);
        return tot;
    }
    int countSubsequenceWithTargetSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return recur(nums, k, 0, 0);
    }
};


class Solution2 {
public:
    int faseExpo(int a, int b, int mod, vector<int> &arr) {
        if(arr[b] != -1) return arr[b];
        long long res = 1;
        while(b) {
            if(b%2 == 1) res = (res * a)%mod;
            a = (1LL * a * a)%mod;
            b >>= 1;
        }
        return arr[b] = res%mod;
    }
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9+7;
        int n = nums.size();
        int tot = 0;
        sort(nums.begin(), nums.end());
        int j = n-1;
        int i=0;
        vector<int> arr(n+1,-1);
        arr[0] = 1;
        for(int i=1;i<=n;i++) {
            arr[i] = (1LL* arr[i-1] * 2)%mod; 
        }
        while(i<=j) {
            int curr = nums[i];
            while(j>=0 && curr + nums[j] > target) j--;
            if(j>=i) {
                tot = ((long long)tot + arr[j-i])%mod;
            }
            i++;
        }
        return tot;
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
class Solution {
public:

    int merge(vector<int> &nums, int l, int mid, int r) {
        vector<int> tmp;

        int i = l;
        int j = mid+1;
        int cnt = 0;
        while(i <= mid && j <= r) {
            if(nums[i] <= nums[j]) {
                tmp.push_back(nums[i]);
                
                i++;
            } else {
                tmp.push_back(nums[j]);
                cnt += (mid - i + 1);
                j++;
            }
        }
        while(i<=mid) {
            tmp.push_back(nums[i]);
            i++;
        }
        while(j<=r) {
            tmp.push_back(nums[j]);
            j++;
        }

        for(int k=0;k<tmp.size();k++) {
            nums[l+k] = tmp[k];
        }
        return cnt;
    }
    int mergeSort(vector<int>& nums, int l, int r) {
        if(l>=r) return 0;
        int mid = (l+r)/2;
        int cnt = 0;
        cnt += mergeSort(nums, l, mid);
        cnt += mergeSort(nums, mid+1, r);
        cnt += merge(nums, l, mid, r);
        return cnt;
    }
    long long int numberOfInversions(vector<int> nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
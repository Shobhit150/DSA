class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();
        int numSum = 0;
        int num2Sum = 0;
        for(int i=0;i<n;i++) {
            numSum += nums[i];
            num2Sum += (nums[i] * nums[i]);
        }

        int normalSum = n*(n+1)/2;
        int normal2Sum = n*(n+1)*(2*n+1)/6;

        int gap = normalSum - numSum;
        int squaregap = normal2Sum - num2Sum;

        int gapSum = squaregap/gap;

        int x = (gap + gapSum)/2;
        int y = gapSum - x;
        return {y,x};
    }

    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int xr = 0;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            xr = xr ^ nums[i] ^ (i+1);
        }
        // int bitNo = 0;

        int bitNo = xr & ~xr;

        // for(int i = 0; i < 31; i++) {
        //     if (xr & (1 << i)) {
        //         bitNo = i;
        //         break;
        //     }
        // }
        int one = 0;
        int zero = 0;
        for(int i=0;i<n;i++) {
            if(((1 << bitNo) & nums[i]) != 0) {
                one ^= nums[i];
            } else {
                zero ^= nums[i];
            }

            if(((1 << bitNo) & (i+1)) != 0) {
                one ^= (i+1);
            } else {
                zero ^= (i+1);
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] == one) cnt++;
        }
        if(cnt == 2) return {one, zero};
        return {zero, one};
    }
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        int t = 0;
        int b = m - 1;
        int l = 0;
        int r = n - 1;
        while(b >= t && r >= l) {
            for(int i=l;i<=r;i++) {
                res.push_back(matrix[t][i]);
            }
            t++;

            for(int i=t;i<=b;i++) {
                res.push_back(matrix[i][r]);
            }
            r--;

            if(t<=b) {
                for(int i=r;i>=l;i--) {
                    res.push_back(matrix[b][i]);
                }
                b--;
            }

            if(l<=r) {
                for(int i=b;i>=t;i--) {
                    res.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return res;
    }
};
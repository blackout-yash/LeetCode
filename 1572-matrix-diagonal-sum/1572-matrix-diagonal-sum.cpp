class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), i = 0, j1 = 0, j2 = n - 1, ans = 0;
        while(i < n) {
            ans += (mat[i][j1] + mat[i][j2]);
            i++; j1++; j2--;
        }
        if(n & 1) ans -= mat[n / 2][n / 2];
        return ans;
    }
};
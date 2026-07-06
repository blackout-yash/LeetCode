class Solution {
public:
    int findMax(int n, int col, vector <vector <int>> &mat) {
        int mx = mat[0][col];
        for(int row = 0; row < n; row++) mx = max(mx, mat[row][col]);
        return mx;
    }

    vector <int> findPeakGrid(vector <vector <int>> &mat) {
        int n = mat.size(), m = mat[0].size(), low = 0, high = m - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(findMax(n, mid, mat) < findMax(n, mid + 1, mat)) low = mid + 1;
            else high = mid;
        }

        int mx = findMax(n, low, mat);
        for(int row = 0; row < n; row++) {
            if(mat[row][low] == mx) return {row, low};
        }
        return {-1, -1};
    }
};
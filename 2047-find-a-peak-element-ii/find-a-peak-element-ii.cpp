class Solution {
public:
    int findMaxIndex(int n, int col, vector <vector <int>> &mat) {
        int index = 0, mx = mat[0][col];
        for(int row = 0; row < n; row++) {
            if(mat[row][col] > mx) {
                index = row;
                mx = mat[row][col];
            }
        }
        return index;
    }

    vector <int> findPeakGrid(vector <vector <int>> &mat) {
        int n = mat.size(), m = mat[0].size(), low = 0, high = m - 1;
        while(low < high) {
            int mid = low + (high - low) / 2,
                index = findMaxIndex(n, mid, mat);
            if(mat[index][mid] < mat[index][mid + 1]) low = mid + 1;
            else high = mid;
        }

        return {findMaxIndex(n, low, mat), low};
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size(), low = 0, high = (n * m) - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2,
                i = mid / m, 
                j = mid % m;
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) high = mid - 1;
            else low = mid + 1;
        }
        return 0;
    }
};
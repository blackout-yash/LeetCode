class Solution {
public:
    void _row(int i, int j, int n, vector<vector<int>> &matrix) {
        while(i < n) matrix[i++][j] = 0;
    }
    
    void _col(int i, int j, int m, vector<vector<int>> &matrix) {
        while(j < m) matrix[i][j++] = 0;
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector <int> row(n), col(m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!matrix[i][j]) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        
        for(int i = 0; i < m; i++) if(col[i]) _row(0, i, n, matrix);
        for(int i = 0; i < n; i++) if(row[i]) _col(i, 0, m, matrix);
    } 
};
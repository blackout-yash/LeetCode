class Solution {
public:
    void row(int i, int j, int n, vector<vector<int>> &matrix) {
        while(i < n) matrix[i++][j] = 0;
    }
    
    void col(int i, int j, int m, vector<vector<int>> &matrix) {
        while(j < m) matrix[i][j++] = 0;
    }
    
    void setZeroesUtil(int i, int j, int n, int m, vector<vector<int>> &matrix) {
        if(i == n) return;
        bool flag = (!matrix[i][j]) ? 1 : 0,
             flag1 = (i + 1 != n && !matrix[i + 1][j]), 
             flag2 = (j + 1 != m && !matrix[i][j + 1]);
        
        int curr_i = i, curr_j = j;
        if(curr_j + 1 == m) curr_i++, curr_j = 0;
        else curr_j++;
        
        setZeroesUtil(curr_i, curr_j, n, m, matrix);
            
        if(flag) {
            if(!flag1) row(0, j, n, matrix);
            if(!flag2) col(i, 0, m, matrix);
        }
    } 
    
    void setZeroes(vector<vector<int>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        setZeroesUtil(0, 0, n, m, matrix);
    } 
};
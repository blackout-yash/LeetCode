class Solution {
public:
    int checkSum(int x, int y, int size, vector <vector <int>> &vert) {
        int sum = 0, j = y + size - 1;
        for(int i = x; i < x + size; i++) {
            sum += vert[i][j];
            if(y) sum -= vert[i][y - 1];
        }
        return sum;
    } 

    bool isPossible(int n, int m, int size, int threshold, vector <vector <int>> &vert) {
        for(int i = 0; i <= n - size; i++) {
            for(int j = 0; j <= m - size; j++) {
                if(threshold >= checkSum(i, j, size, vert)) return true;
            }
        }
        return false;
    }

    int maxSideLength(vector <vector <int>> &mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        vector <vector <int>> vert(n, vector <int> (m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vert[i][j] = mat[i][j];
                if(j) vert[i][j] += vert[i][j - 1];
            }
        }
        
        int low = 1, high = min(n, m), ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(n, m, mid, threshold, vert)) {
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return ans;
    }
};
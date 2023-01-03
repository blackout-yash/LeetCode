class Solution {
public:
    int minDeletionSize(vector <string> &strs) {
        int ans = 0, n = strs.size(), m = strs[0].size();
        for(int j = 0; j < m; j++) {
            char prev = 'a';
            for(int i = 0; i < n; i++) {
                if(prev > strs[i][j]) {
                    ans++;
                    break;
                } else prev = strs[i][j];
            }
        }
        return ans;
    }
};
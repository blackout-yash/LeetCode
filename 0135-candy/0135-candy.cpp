class Solution {
public:
    int candy(vector <int> &ratings) {
        int n = ratings.size();
        vector <int> left(n), right(n);
        
        int prev = 1e9, size = 0;
        for(int i = 0; i < n; i++) {
            if(ratings[i] > prev) size++;
            else size = 0;
            left[i] = size;
            prev = ratings[i];
        }
        
        prev = 1e9; size = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(ratings[i] > prev) size++;
            else size = 0;
            right[i] = size;
            prev = ratings[i];
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) ans += 1 + max(left[i], right[i]);
        
        return ans;
    }
};
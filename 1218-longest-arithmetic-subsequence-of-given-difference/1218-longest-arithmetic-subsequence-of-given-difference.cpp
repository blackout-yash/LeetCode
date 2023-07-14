class Solution {
public:    
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 0;
        unordered_map <int, int> m;
        for(auto x: arr) {
            int num = x - difference,
                curr = m[num] + 1;
            m[x] = curr;
            ans = max(ans, curr);
        }
        return ans;
    }
};
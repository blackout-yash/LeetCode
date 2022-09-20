class Solution {
public:
    int findLength(int n, int m, vector<int> &nums1, vector<int> &nums2, vector <vector <int>> &dp) {
        if(n == -1 || m == -1) return 0;
        else if(dp[n][m] != -1) return dp[n][m];
        
        int taken = 0;
        if(nums1[n] == nums2[m]) taken = 1 + findLength(n - 1, m - 1, nums1, nums2, dp);
        
        findLength(n - 1, m, nums1, nums2, dp);
        findLength(n, m - 1, nums1, nums2, dp);        
        
        return dp[n][m] = taken;
    }
    
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size(), m = nums2.size();
        vector <vector <int>> dp(n, vector <int> (m, -1));
        findLength(n - 1, m - 1, nums1, nums2, dp);
        
        int ans = 0;
        for(auto x: dp){
            for(auto y: x) ans = max(ans, y);
        }
        
        return ans;
    }
};
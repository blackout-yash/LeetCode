class Solution {
public:  
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size(), m = nums2.size();
        vector <vector <int>> dp(n, vector <int> (m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(nums1[i] == nums2[j]) {
                    if(i && j) dp[i][j] = 1 + dp[i - 1][j - 1];
                    else dp[i][j] = 1;
                }
            }
        }
        
        int ans = 0;
        for(auto x: dp){
            for(auto y: x) ans = max(ans, y);
        }
        
        return ans;
    }
};
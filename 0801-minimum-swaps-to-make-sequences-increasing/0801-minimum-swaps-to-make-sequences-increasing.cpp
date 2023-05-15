class Solution {
public:
    int findMin(int a, int b, int c, int d, int x, int y) {
        int ans = 1e9;
        if(a > c && b > d) ans = min(ans, x);
        if(a > d && b > c) ans = min(ans, y);
        return ans;
    }
    
    int minSwap(vector <int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        vector <vector <int>> dp(n, vector <int> (2));
        dp[0][1] = 1;
        for(int i = 1; i < n; i++) {
            dp[i][0] = findMin(nums1[i], nums2[i], nums1[i - 1], nums2[i - 1], dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = 1 + findMin(nums2[i], nums1[i], nums1[i - 1], nums2[i - 1], dp[i - 1][0], dp[i - 1][1]);
        }
        return min(dp[n - 1][0], dp[n - 1][1]);
    }
};
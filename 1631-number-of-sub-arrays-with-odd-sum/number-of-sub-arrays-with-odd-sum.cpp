class Solution {
public:
    int add(long a, long b, int mod = 1e9 + 7) {return (((a+b)%mod)+mod)%mod;}

    int numOfSubarrays(vector <int> &arr) {
        int n = arr.size(), ans = (arr[0] & 1);
        vector <vector <int>> dp(n, vector <int> (2));
        dp[0][arr[0] & 1] = 1;
        for(int i = 1; i < n; i++) {
            if(arr[i] & 1) {
                dp[i][0] = add(dp[i][0], dp[i - 1][1]);
                dp[i][1] = add(dp[i][1], dp[i - 1][0] + 1); 
            } else {
                dp[i][0] = add(dp[i][0], dp[i - 1][0] + 1);
                dp[i][1] = add(dp[i][1], dp[i - 1][1]);
            }
            ans = add(ans, dp[i][1]); 
        }
        return ans;
    }
};
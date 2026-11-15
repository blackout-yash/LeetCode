class Solution {
public:
    int add(long a, long b, int mod = 1e9 + 7) {return (((a+b)%mod)+mod)%mod;}

    int numOfSubarrays(vector <int> &arr) {
        int n = arr.size(), ans = (arr[0] & 1);
        vector <int> dp(2);
        dp[arr[0] & 1] = 1;
        for(int i = 1; i < n; i++) {
            vector <int> curr(2);
            if(arr[i] & 1) {
                curr[0] = add(curr[0], dp[1]);
                curr[1] = add(curr[1], dp[0] + 1); 
            } else {
                curr[0] = add(curr[0], dp[0] + 1);
                curr[1] = add(curr[1], dp[1]);
            }
            ans = add(ans, curr[1]);
            dp = curr;
        }
        return ans;
    }
};
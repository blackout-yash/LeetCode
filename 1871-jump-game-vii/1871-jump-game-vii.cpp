class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector <int> dp(n);
        dp[0] = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == '1') dp[i] = dp[i - 1];
            else {
                int left = max(0, i - maxJump), right = i - minJump;
                if(right < 0) {
                    dp[i] = dp[i - 1];
                    continue;
                }
                
                int sum = dp[right];
                if(left) sum -= dp[left - 1];
                
                dp[i] = dp[i - 1] + (sum > 0);
            }
        }
                
        return dp[n - 1] - dp[n - 2];
    }
};
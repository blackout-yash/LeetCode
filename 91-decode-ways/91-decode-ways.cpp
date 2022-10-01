class Solution {
public:
    bool isPossible(char a, char b){
        int num1 = 10 * (a - '0'), num2 = (b - '0');
        if(num1 && num1 + num2 <= 26) return true;
        return false;
    }
    
    int numDecodings(string s) {
        int n = s.size();
        vector <int> dp(n + 1);
        
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            if(s[i - 1] != '0') dp[i] = dp[i - 1];
            if(i >= 2 && isPossible(s[i - 2], s[i - 1])) dp[i] += dp[i - 2];
        }
        
        return dp[n];
    }
};
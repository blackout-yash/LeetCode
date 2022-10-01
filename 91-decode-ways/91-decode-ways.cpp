class Solution {
public:
    bool isPossible(char a, char b){
        int num1 = 10 * (a - '0'), num2 = (b - '0');
        if(num1 && num1 + num2 <= 26) return true;
        return false;
    }
    
    int numDecodings(int i, int n, string &s, vector <int> &dp) {
        if(i == n) return 1;
        else if(dp[i] != -1) return dp[i];
        
        int ans1 = 0, ans2 = 0;
        if(s[i] != '0') ans1 = numDecodings(i + 1, n, s, dp);
        if(i + 2 <= n && isPossible(s[i], s[i + 1])) ans2 = numDecodings(i + 2, n, s, dp);
        
        return dp[i] = (ans1 + ans2);
    }
    
    int numDecodings(string s) {
        int n = s.size();
        vector <int> dp(n, -1);
        
        int ans = numDecodings(0, n, s, dp);
        return ans;
    }
};
class Solution {
public:
    bool wordBreak(string str, vector <string> &wordDict) {
        set <string> s;
        for(auto x: wordDict) s.insert(x);
        
        int n = str.size();
        vector <int> dp(n + 1); dp[n] = 1;
        for(int i = n - 1; i >= 0; i--) {
            string curr;
            for(int j = i; j < n; j++) {
                curr.push_back(str[j]);
                if(s.find(curr) != s.end() && dp[j + 1]) dp[i] = 1;
            }
        }
        return dp[0];
    }
};
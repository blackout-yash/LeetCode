class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        map <string, bool> m;
        for(auto x: dictionary) m[x] = true;
        
        int n = s.size();
        vector <int> dp(n + 1, 1e9); dp[n] = 0;
        for(int i = n - 1; i >= 0; i--) {
            string curr; int size = 0;
            for(int j = i; j < n; j++) {
                curr.push_back(s[j]);
                if(m.count(curr)) size = 0;
                else size++;
                dp[i] = min(dp[i], size + dp[j + 1]);
            }
        }
        
        return dp[0];
    }
};
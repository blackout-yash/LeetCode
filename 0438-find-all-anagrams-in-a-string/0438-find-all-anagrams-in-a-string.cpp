class Solution {
public:
    int sum(int i, int j, int k, vector <vector <int>> &dp){
        int ans = dp[i][j];
        if(k) ans -= dp[k - 1][j];
        return ans;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector <int> store(26);
        for(auto x: p) store[x - 'a']++;
        
        
        int n = s.size(), m = p.size(), cnt = 0, k = 0;
        vector <int> ans;
        vector <vector <int>> dp(n, vector <int> (26));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 26; j++){
                if(i) dp[i][j] = dp[i - 1][j];
            } dp[i][s[i] - 'a']++;
            
            cnt++;
            if(cnt == m){
                bool flag = 1;
                for(int j = 0; j < 26; j++){
                    if(sum(i, j, k, dp) != store[j]) {
                        flag = 0;
                        break;
                    }
                }
                if(flag) ans.push_back(k);
                cnt--; k++;
            }
        }       
        return ans;
    }
};
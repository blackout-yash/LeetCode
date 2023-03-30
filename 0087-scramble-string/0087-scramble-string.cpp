class Solution {
public:
    bool isSame(int i, int j, int n, string &s1, string &s2) {
        while(n--){
            if(s1[i] != s2[j]) return false;
            i++; j++;
        }
        return true;
    }
    
    bool isScrambleUtils(int i, int j, int n, string &s1, string &s2, vector <vector <vector <int>>> &dp) {
        if(isSame(i, j, n, s1, s2)) return true;
        else if(n == 1) return false;
        else if(dp[i][j][n] != -1) return dp[i][j][n];
        
        bool ans = false;
        for(int k = i; k < i + n - 1; k++) {
            int m = (k - i) + 1;
            bool flag1 = isScrambleUtils(i, j + m, n - m, s1, s2, dp),
                 flag2 = isScrambleUtils(i + n - m, j, m, s1, s2, dp),
                 flag3 = isScrambleUtils(i, j, m, s1, s2, dp),
                 flag4 = isScrambleUtils(i + m, j + m, n - m, s1, s2, dp);
            ans |= (flag1 && flag2) || (flag3 && flag4);
        }
        
        return dp[i][j][n] = ans;
    }
    
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector <vector <vector <int>>> dp(n, vector <vector <int>> (n, vector <int> (n + 1, -1)));
        return isScrambleUtils(0, 0, n, s1, s2, dp);
    }
};
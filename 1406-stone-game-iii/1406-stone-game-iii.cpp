class Solution {
public:
    int stoneGameIII(int i, vector<int> &piles, int turn, vector<vector<int>> &dp){
        if(i >= piles.size()) return 0;
        else if(dp[i][turn] != -1) return dp[i][turn];
        
        int alice = 0,
            ans = INT_MIN;
        if(turn == 1) ans = INT_MAX;

        for(int j = 0; j < 3; j++){
            int k = i + j;
            if(k >= piles.size()) break;
            alice += piles[k];

            if(turn == 0) ans = max(ans, alice + stoneGameIII(k + 1, piles, 1, dp));
            else ans = min(ans, stoneGameIII(k + 1, piles, 0, dp));
        }

        return dp[i][turn] = ans;
    }
    
    string stoneGameIII(vector <int> &piles) {
        int n = piles.size();
        vector <vector <int>> dp(n + 1, vector <int> (2, -1));
        
        int alice = stoneGameIII(0, piles, 0, dp),
            total = 0;
        for(auto i:piles) total += i;
        
        int bob = total - alice;

        if(alice > bob){
            return "Alice";
        } else if(bob > alice){
            return "Bob";
        }
        return "Tie";
    }
};
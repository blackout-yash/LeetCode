class Solution {
public:
    int sum(int a, int b, int m = 1e9 + 7) {a %= m; b %= m; return (((a + b) % m) + m) % m;}
    
    int countRoutes(vector <int> &locations, int start, int finish, int fuel) {
         int n = locations.size();
         vector <vector <int>> dp (n, vector <int> (fuel + 1));

         dp[start][fuel] = 1;
         for(int f = fuel; f >= 0; f--){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    int diff = abs(locations[i] - locations[j]);
                    if(i != j && f >= diff)
                    dp[j][f - diff] = sum(dp[j][f - diff], dp[i][f]);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i <= fuel; i++) ans = sum(ans, dp[finish][i]);

        return ans;   
    }
};
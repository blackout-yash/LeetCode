class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        set <int> s;
        for(auto x: arr2) s.insert(x);
        int k = 0;
        for(auto x: s) arr2[k++] = x;
    
        int n = arr1.size(), m = s.size();
        vector <vector <int>> dp(n, vector <int> (m + 1, 1e9));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= m; j++) {
                if(j == m) {
                    if(i) {}
                    else dp[i][j] = 0;
                } else {
                    if(i) {
                        int min1 = 1e9, min2 = 1e9, min3 = 1e9;
                        if(j) {
                            min1 = dp[i][j - 1];
                            min2 = 1 + dp[i - 1][j - 1];
                        }
                        if(arr1[i - 1] < arr2[j]) min3 = 1 + dp[i - 1][m];
                        dp[i][j] = min({min1, min2, min3});
                    } else dp[i][j] = 1;
                }
                
                int num = arr1[i];
                if(j != m) num = arr2[j];                
                if(i + 1 != n && arr1[i + 1] > num) dp[i + 1][m] = min(dp[i + 1][m], dp[i][j]);
            }
        }
        
        int ans = *min_element(begin(dp[n - 1]), end(dp[n - 1]));
        if(ans >= 1e9) return -1;
        return ans;
    }
};
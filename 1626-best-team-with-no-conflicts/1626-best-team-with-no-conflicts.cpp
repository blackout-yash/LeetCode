#define ff first
#define ss second
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector <pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) arr[i] = {ages[i], scores[i]};
        sort(arr.begin(), arr.end());
        
        int ans = 0;
        vector <int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = arr[i].ss;
            for (int j = i - 1; j >= 0; j--) {
                if (arr[i].ff == arr[j].ff) dp[i] = max(dp[i], dp[j] + arr[i].ss);
                else if (arr[i].ss >= arr[j].ss) dp[i] = max(dp[i], dp[j] + arr[i].ss);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
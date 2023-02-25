class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, _max = 0, n = prices.size();
        for(int i = n - 1; i >= 0; i--) {
            ans = max(ans, _max - prices[i]);
            _max = max(_max, prices[i]);
        }
        return ans;
    }
};
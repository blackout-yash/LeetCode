class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();

        int buy = 0, sell = 0;
        for (int i = 0; i < n; i++) {
            int currBuy = 0, currSell = 0;
            if (i) {
                int ans1 = -prices[i] + buy;
                int ans2 = sell;
                currSell = max(ans1, ans2);

                int ans3 = prices[i] + sell - fee;
                int ans4 = buy;
                currBuy = max(ans3, ans4);
            } else currSell = -prices[i];

            buy = currBuy;
            sell = currSell;
        }

        return buy;
    }
};

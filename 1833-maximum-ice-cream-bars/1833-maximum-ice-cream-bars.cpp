class Solution {
public:
    int maxIceCream(vector <int> &costs, int coins) {
        int ans = 0;
        sort(costs.begin(), costs.end());
        for(auto x: costs) {
            coins -= x;
            if(coins >= 0) ans++;
            else break;
        } 
        return ans;
    }
};
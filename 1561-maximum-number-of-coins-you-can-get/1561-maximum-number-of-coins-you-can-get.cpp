class Solution {
public:
    int maxCoins(vector <int> &piles) {
        sort(begin(piles), end(piles));
        int n = piles.size(), i = 0, j = n - 2, k = n - 1, ans = 0;
        while(i < j) {
            ans += piles[j];
            i++; j -= 2; k -= 2;
        }
        return ans;
    }
};
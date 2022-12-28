class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        set <pair <int, int>> s;
        int total = 0, n = piles.size();
        for(int i = 0; i < n; i++) {
            total += piles[i];
            s.insert({piles[i], i});
        }
        
        while(k--) {
            if(!total || s.empty()) break;
            auto it = *s.rbegin();
            s.erase(it);
            total -= it.first;
            it.first -= it.first/2;
            total += it.first;
            if(it.first > 1) s.insert(it);
        }
        return total;
    }
};
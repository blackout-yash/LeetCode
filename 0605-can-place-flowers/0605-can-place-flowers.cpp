class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int k) {
        int n = flowerbed.size();
        flowerbed.push_back(0);
        for(int i = 0; i < n; i++) {
            if(!k) break;
            else if(flowerbed[i]) continue;
            bool flag1 = !i;
            if(i) flag1 = !flowerbed[i - 1];
            bool flag2 = !flowerbed[i + 1];
            if(flag1 && flag2) {
                flowerbed[i] = 1;
                k--;
            }
        }
        return !k;
    }
};
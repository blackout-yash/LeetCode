class Solution {
public:
    int singleNumber(vector <int> &nums) {
        int cnt = 0;
        vector <int> bit(35);
        for(auto x: nums) {
            if(x < 0) cnt++;
            int j = 0;
            while(x) {
                if(x & 1) bit[j]++;
                x /= 2; j++;
            }
        }
        
        long ans = 0, curr = 1;
        for(auto x: bit) {
            if(x % 3) ans += curr;
            curr *= 2;
        }
        if(cnt % 3) return -ans;
        return ans;
    }
};
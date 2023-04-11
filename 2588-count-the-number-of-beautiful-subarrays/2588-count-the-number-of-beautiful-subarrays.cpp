class Solution {
public:
    void setBit(int n, vector <int> &bit) {
        int i = 0;
        while(n) {
            if(n & 1) bit[i] = !bit[i];
            n >>= 1; i++;
        }
    }
    
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans = 0;
        vector <int> bit(20);
        map <vector <int>, int> m;
        m[bit] = 1;
        for(auto x: nums) {
            setBit(x, bit);
            vector <int> req(20);
            for(int i = 0; i < 20; i++) {
                if(bit[i]) req[i] = 1;
            }
            ans += m[req];
            m[bit]++;
        }
        return ans;
    }
};


class Solution {
public:
    void setBit(long long n, long long &curr) {
        long long i = 0, temp = 1;
        while(n) {
            if(n & 1) {
                if(curr & temp) curr -= temp;
                else curr += temp;
            }
            temp <<= 1; n >>= 1; i++;
        }
    }
    
    long long cal(long long curr) {
        long long req = 0, temp = 1;
        while(curr) {
            if(curr & 1) req += temp;
            temp <<= 1; curr >>= 1;
        }
        return req;
    }
    
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans = 0;
        vector <long long> cnt(1 << 21);
        cnt[0] = 1; long long curr = 0;
        for(auto x: nums) {
            setBit(x, curr);
            long long req = cal(curr);
            ans += cnt[req];
            cnt[curr]++;
        }
        return ans;
    }
};


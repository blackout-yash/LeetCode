class Solution {
public:
    bool isPossible(int k, int h, vector <int> &piles) {
        long req = 0;
        for(auto x: piles) req += ((x / k) + ((x % k) != 0));
        return (h >= req);
    }
    
    int minEatingSpeed(vector <int> &piles, int h) {
        int low = 1, high = 1e9, ans = high;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(mid, h, piles)) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }
};
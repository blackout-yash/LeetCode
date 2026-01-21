class Solution {
public:
    int convert(int x) {
        if(x == 2) return -1;

        int prev = 1, flag = true, ans = 0;
        while(x) {
            if(x & 1) ans += prev;
            else if(flag) {
                flag = 0;
                ans -= (prev / 2);
            }
            x /= 2; prev *= 2;
        }
        if(flag) ans -= (prev / 2);
        return ans;
    }

    vector <int> minBitwiseArray(vector<int>& nums) {
        vector <int> ans;
        for(auto x: nums) ans.push_back(convert(x));
        return ans;
    }
};
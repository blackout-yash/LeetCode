class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        map <int, int> m; m[0] = 1;
        for(auto x: nums) {
            sum += x; 
            sum = ((sum % k) + k) % k;
            ans += m[sum];
            m[sum]++;
        }
        return ans;
    }
};
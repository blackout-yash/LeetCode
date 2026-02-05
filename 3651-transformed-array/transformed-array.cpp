class Solution {
public:
    vector <int> constructTransformedArray(vector <int> &nums) {
        int n = nums.size();
        vector <int> ans(n);
        for(int i = 0; i < n; i++) {
            int curr = (((i + nums[i] + n) % n) + n) % n;
            ans[i] = nums[curr];
        }   
        return ans;
    }
};
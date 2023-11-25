class Solution {
public:
    vector <int> getSumAbsoluteDifferences(vector <int> &nums) {
        vector <int> sorted = nums;
        sort(begin(sorted), end(sorted));
        
        int n = nums.size();
        vector <int> sum(n);
        for(int i = 0; i < n; i++) sum[i] = nums[i] + ((i) ? sum[i - 1] : 0);
    
        vector <int> ans(n);
        for(int i = 0; i < n; i++) {
            int ind = upper_bound(begin(sorted), end(sorted), nums[i]) - sorted.begin(),
                curr = nums[i] * (2 * ind - n) + sum[n - 1] - 2 * sum[ind - 1];
            ans[i] = curr;
        }
        return ans;
    }
};
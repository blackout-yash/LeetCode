class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector <int> ans;
        long n = nums.size(), left = 0, right = nums[0], size1 = 0, size2 = 1, l = 0, r = 1;
        for(int i = 0; i < n; i++) {
            right -= nums[i]; size2--;
            while(size2 < k && r < n) right += nums[r++], size2++;
            
            if(size1 == k && size2 == k) {
                long curr = left + nums[i] + right,
                    range = (2 * k) + 1;
                ans.push_back(curr / range);
            } else ans.push_back(-1);
            
            left += nums[i]; size1++;
            if(size1 == k + 1) left -= nums[l++], size1--;
        }
        return ans;
    }
};
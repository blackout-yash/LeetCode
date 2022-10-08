class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans, diff = 1e9;
        for(int i = 0; i < n - 2; i++){
            int j = i + 1, k = n - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k],
                    curr = abs(target - sum);
                if(diff > curr) {
                    ans = sum;
                    diff = curr;
                }
                if(sum <= target) j++;
                else k--;
            }
        }
        return ans;
    }
};
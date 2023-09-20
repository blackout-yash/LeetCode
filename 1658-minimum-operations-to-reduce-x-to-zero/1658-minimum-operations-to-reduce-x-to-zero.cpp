class Solution {
public:
    int minOperations(vector <int> &nums, int x) {
        int n = nums.size(), i = -1, j = 1, sum1 = 0, sum2 = 0, ans = 1e9;
        for(int i = 1; i < n; i++) sum2 += nums[i];
        while(i < n - 1) {
            sum1 += nums[++i];
            while(j < n) {
                if(sum2 == x) ans = min(ans, n - j);
                if(sum1 + sum2 <= x) break;
                else sum2 -= nums[j++];
            }
            if(sum1 == x) ans = min(ans, i + 1);
            if(sum1 + sum2 == x && i < j) ans = min(ans, i + 1 + n - j);
        }
        if(ans == 1e9) ans = -1;
        return ans;
    }
};
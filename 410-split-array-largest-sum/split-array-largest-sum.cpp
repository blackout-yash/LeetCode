class Solution {
public:
    int isPossible(int sum, vector <int> &nums) {
        int cnt = 0, curr = 0;
        for(auto x: nums) {
            if(sum <= x + curr) {
                cnt++;
                if(sum == x + curr) curr = 0;
                else curr = x;
            } else curr += x;
        }
        if(curr) cnt++;
        return cnt;
    }

    int splitArray(vector <int> &nums, int k) {
        int n = nums.size();
        if(k > n) return -1;

        int low = *max_element(begin(nums), end(nums)),
            high = accumulate(begin(nums), end(nums), 0),
            ans = high;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(mid, nums) <= k) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }

        return ans;
    }
};
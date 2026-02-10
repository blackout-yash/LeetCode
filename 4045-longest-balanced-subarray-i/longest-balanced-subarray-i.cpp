class Solution {
public:
    int longestBalanced(vector <int> &nums) {
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            map <int, int> odd, even;
            for(int j = i; j < n; j++) {
                if(nums[j] & 1) odd[nums[j]]++;
                else even[nums[j]]++;
                if(odd.size() == even.size()) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
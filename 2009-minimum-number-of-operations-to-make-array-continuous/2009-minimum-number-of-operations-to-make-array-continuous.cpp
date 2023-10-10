class Solution {
public:
    int minOperations(vector <int> &nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        
        map <int, int> m;
        int j = 0, ans = n;
        for(int i = 0; i < n; i++) {
            while(j < n) {
                if(nums[j] >= nums[i] + n) break;
                else m[nums[j++]]++;
            } 
            ans = min(ans, int(n - m.size()));
            if(m[nums[i]] == 1) m.erase(nums[i]);
            else m[nums[i]]--;
        }
        return ans;
    }
};
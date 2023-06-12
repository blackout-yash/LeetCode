class Solution {
public:
    vector <string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector <string> result;
        if(n == 0) return result;
        
        int a = nums[0];
        for(int i = 0; i < n; i++) {
            if(i == n - 1 || nums[i] + 1 != nums[i + 1]) {
                if(nums[i] != a) result.push_back(to_string(a) + "->" + to_string(nums[i]));
                else result.push_back(to_string(a));
                if(i != n - 1) a = nums[i + 1];
            }
        }
        return result;
    }
};
class Solution {
public:
    void permute(int n, vector <int> &curr, vector <int> &nums, vector<vector<int>> &ans) {
        if(n == -1) {
            ans.push_back(curr);
            return;
        }
        
        for(auto &x: nums) {
            if(x == -1e9) continue;
            curr.push_back(x);
            x = -1e9;
            permute(n - 1, curr, nums, ans);
            x = curr.back();
            curr.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector <int> curr;
        vector<vector<int>> ans;
        permute(nums.size() - 1, curr, nums, ans);
        return ans;
    }
};
class Solution {
public:
    set <vector <int>> s;
    void findSubsequencesUtil(int i, vector <int> &curr, vector <int> &nums) {
        if(i == nums.size()) return;
        
        if(curr.empty() || curr.back() <= nums[i]) {
            curr.push_back(nums[i]);
            if(curr.size() > 1) s.insert(curr);
            findSubsequencesUtil(i + 1, curr, nums);
            curr.pop_back();
        }
        findSubsequencesUtil(i + 1, curr, nums);
    }
    
    vector<vector<int>> findSubsequences(vector <int> &nums) {
        int i = 0;
        vector <int> curr;
        findSubsequencesUtil(i, curr, nums);
        vector<vector<int>> ans;
        for(auto x: s) ans.push_back(x);
        return ans;
    }
};
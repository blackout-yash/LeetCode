class Solution {
public:
    bool isEven(int n){
        return !(n & 1);
    }
    
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries) {
        int sum = 0;
        for(auto x: nums) {
            if(isEven(x)) sum += x;
        }
        
        vector <int> ans;
        for(auto x: queries){
            if(isEven(nums[x[1]])) sum -= nums[x[1]];
            nums[x[1]] += x[0];
            if(isEven(nums[x[1]])) sum += nums[x[1]];
            ans.push_back(sum);
        }
        return ans;
    }
};
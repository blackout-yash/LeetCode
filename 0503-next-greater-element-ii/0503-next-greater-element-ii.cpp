class Solution {
public:
    vector<int> nextGreaterElements(vector <int> &nums) {
        stack <int> s;
        int n = nums.size();
        vector <int> ans(n);
        for(int i = (2* n) - 1; i >= 0; i--) {
            int ind = i % n;
            while(s.size()) {
                if(s.top() > nums[ind]) break;
                else s.pop();
            }
            if(s.empty()) ans[ind] = -1;
            else ans[ind] = s.top();
            while(s.size()) {
                if(nums[ind] >= s.top()) s.pop();
                else break;
            }
            s.push(nums[ind]);
        }
        return ans;
    }
};
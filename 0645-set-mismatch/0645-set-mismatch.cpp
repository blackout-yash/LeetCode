class Solution {
public:
    vector <int> findErrorNums(vector<int>& nums) {
        vector <int> ans;
        map <int, int> m;
        for(auto x: nums) {
            if(m.count(x)) ans.push_back(x);
            else m[x] = 1;
        }
        
        for(int i = 1; i <= nums.size(); i++) {
            if(!m.count(i)) ans.push_back(i);
        }
        return ans;
    }
};
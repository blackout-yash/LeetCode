class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if(k == 0) return {{}};
        
        vector <vector <int>> ans;
        for(int i = n; i >= 1; i--) {
            vector <vector <int>> temp = combine(i - 1, k - 1);
            for(auto x: temp) {
                x.push_back(i);
                ans.push_back(x);
            }
        }
        return ans;
    }
};
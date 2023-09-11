class Solution {
public:
    vector<vector<int>> groupThePeople(vector <int> &groupSizes) {
        map <int, vector <int>> m;
        int n = groupSizes.size();
        for(int i = 0; i < n; i++) m[groupSizes[i]].push_back(i);
        
        vector <vector <int>> ans;
        for(auto x: m) {
            vector <int> curr;
            for(auto y: x.second) {
                curr.push_back(y);
                if(curr.size() == x.first) {
                    ans.push_back(curr);
                    curr.clear();
                }
            }
        }
        return ans;
    }
};
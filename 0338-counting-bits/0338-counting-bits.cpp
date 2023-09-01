class Solution {
public:
    vector<int> countBits(int n) {
        int j = 0, size = 1;
        vector <int> ans = {0};
        for(int i = 0; i < n; i++) {
            ans.push_back(ans[j++] + 1);
            if(j == size) {
                size *= 2; j = 0;
            }
        }
        return ans;
    }
};
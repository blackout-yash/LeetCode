class Solution {
public:
    vector <int> kWeakestRows(vector <vector <int>> &mat, int k) {
        int n = mat.size();
        vector <pair <int, int>> arr;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(auto y: mat[i]) sum += y;
            arr.push_back({sum, i});
        }
        sort(begin(arr), end(arr));
        
        vector <int> ans;
        for(int i = 0; i < k; i++) ans.push_back(arr[i].second);
        return ans;
    }
};
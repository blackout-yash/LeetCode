class Solution {
public:
    vector <vector <int>> minimumAbsDifference(vector <int> &arr) {
        vector <vector <int>> ans;
        sort(begin(arr), end(arr));
        int mn = INT_MAX, n = arr.size();
        for(int i = 0; i < n - 1; i++) {
            int diff = arr[i + 1] - arr[i];
            if(mn > diff) {
                mn = diff;
                ans.clear();
            }
            if(diff == mn) ans.push_back({arr[i], arr[i + 1]});
        }
        return ans;
    }
};
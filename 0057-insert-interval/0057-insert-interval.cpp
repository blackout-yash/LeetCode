class Solution {
public:
    bool insert(vector <int> &y, vector <vector <int>> &ans) {
        int n = ans.size(),
            r1 = ans[n - 1][1],
            l2 = y[0];
        if (l2 <= r1) {
            ans[n - 1][0] = min(ans[n - 1][0], y[0]);
            ans[n - 1][1] = max(ans[n - 1][1], y[1]);
            return true;
        } return false;
    }

    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int>  &newInterval) {
        int n = intervals.size();
        vector <vector <int>> ans;
        for (int i = 0; i < n; i++) {
            if (ans.empty()) {
                if(newInterval[1] < intervals[i][0]) {
                    ans.push_back(newInterval);
                    newInterval.clear();
                }
                ans.push_back(intervals[i]);
            } else {
                if (insert(intervals[i], ans)) {}
                else ans.push_back(intervals[i]);
            }

            if (newInterval.size()) {
                if (insert(newInterval, ans)) newInterval.clear();
                else if (i + 1 != n) {
                    int n = ans.size(),
                        r1 = ans[n - 1][1],
                        l2 = newInterval[0],
                        l3 = intervals[i + 1][0];
                    if (r1 <= l2 && l2 <= l3) {
                        ans.push_back(newInterval);
                        newInterval.clear();
                    }
                }
            }
        }
        if (newInterval.size()) ans.push_back(newInterval);
        return ans;
    }
};
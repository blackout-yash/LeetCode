class Solution {
public:
    vector <int> leftMin(int n, vector <int> &arr) {
        stack <int> s;
        vector <int> ans(n);
        for (int i = 0; i < n; i++) {
            while (s.size()) {
                if (arr[s.top()] >= arr[i]) s.pop();
                else break;
            }
            if (s.empty()) ans[i] = -1;
            else ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector <int> rightMin(int n, vector <int> &arr) {
        stack <int> s;
        vector <int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (s.size()) {
                if (arr[s.top()] > arr[i]) s.pop();
                else break;
            }
            if (s.empty()) ans[i] = n;
            else ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int> &arr) {
        int n = arr.size();
        vector <int> prefix = leftMin(n, arr),
                     suffix = rightMin(n, arr);

        long ans = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            long left = prefix[i] + 1,
                 right = suffix[i] - 1,
                 cnt1 = i - left,
                 cnt2 = right - i + 1,
                 cnt = (cnt1 + 1) * cnt2,
                 curr = arr[i] * cnt;
            ans = (ans + curr) % mod;
        }
        return ans;
    }
};
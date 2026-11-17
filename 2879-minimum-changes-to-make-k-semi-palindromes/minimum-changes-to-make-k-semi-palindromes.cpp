class Solution {
public:
    vector <int> getDivisors(int n) {
        vector <int> res;
        int num = 1;
        while (num * num <= n) {
            if (n % num == 0) {
                if (num == n / num) res.push_back(num);
                else {
                    res.push_back(num);
                    if(num > 1) res.push_back(n / num);
                }
            }
            num++;
        }
        return res;
    }

    int replacementRequired(string &s) {
        int i = 0, j = s.size() - 1, ans = 0;
        while(i < j) {
            ans += (s[i] != s[j]);
            i++; j--;
        }
        return ans;
    }

    int minimumChanges(string s) {
        int n = s.size();
        vector <int> divisors = getDivisors(n);

        int res = INT_MAX;
        for(auto x: divisors) {
            int currCnt = 0;
            vector <string> curr(x);
            for(int i = 0; i < n; i++) curr[i % x].push_back(s[i]);
            for(auto y: curr) currCnt += replacementRequired(y);
            res = min(res, currCnt);
        }

        return res;
    }

    int minimumChanges(string s, int m) {
        int n = s.size();
        vector <vector <int>> dp(n + 1, vector <int> (n + 1, 1e6));
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                dp[i][j] = minimumChanges(s.substr(i, j - i + 1));
            }
        }

        vector <vector <int>> arr(n + 1, vector <int> (m + 1, 1e6));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                for(int k = 0; k <= m; k++) {
                    if(k == 0) arr[i][0] = 0;
                    else if(k == 1) arr[i][1] = dp[0][i];
                    else arr[i][k] = min(arr[i][k], arr[j][k - 1] + dp[j+1][i]);
                }
            }
        }
        return arr[n - 1][m];
    }
};
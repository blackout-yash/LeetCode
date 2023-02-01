class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans, curr;
        int n = str1.size(), m = str2.size();
        for (int i = 0; i < min(n, m); i++) {
            curr.push_back(str1[i]);
            bool flag = true;
            if(n % (i + 1) || m % (i + 1)) continue;
            for (int j = 0; j < n; j++) {
                if (curr[j % (i + 1)] != str1[j]) flag = false;
            }
            for (int j = 0; j < m; j++) {
                if (curr[j % (i + 1)] != str2[j]) flag = false;
            }
            if (flag) ans = curr;
        }
        return ans;
    }
};
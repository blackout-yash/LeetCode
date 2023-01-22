class Solution {
public:
    vector<vector<string>> ans;
    string isPalindrome(int i, int j, string &s) {
        string str;
        for (int k = i; k <= j; k++) str.push_back(s[k]);
        while (i <= j) {
            if (s[i] != s[j]) return "";
            i++; j--;
        } return str;
    }

    void partitionUtil(int i, int j, vector <string> &temp, string &s) {
        if (j == s.size()) {
            ans.push_back(temp);
            return;
        }

        string str = isPalindrome(i, j, s);
        if (str.size()) {
            temp.push_back(str);
            partitionUtil(j + 1, j + 1, temp, s);
            temp.pop_back();
        } 
        if (j + 1 != s.size())partitionUtil(i, j + 1, temp, s);
    }

    vector<vector<string>> partition(string s) {
        vector <string> temp;
        partitionUtil(0, 0, temp, s);
        return ans;
    }
};
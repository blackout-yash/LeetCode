class Solution {
public:
    vector <string> s = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void letterCombinations(int i, int n, string &curr, vector <string> &ans, string &digits) {    
        if(i == n) {
            ans.push_back(curr);
            return;
        }
        
        for(auto x: s[digits[i] - '0']) {
            curr.push_back(x);
            letterCombinations(i + 1, n, curr, ans, digits);
            curr.pop_back();
        }
    }
    
    vector <string> letterCombinations(string digits) {
        if(digits.empty()) return{};
        string curr;
        vector <string> ans;
        int n = digits.size();
        letterCombinations(0, n, curr, ans, digits);
        return ans;
    }
};
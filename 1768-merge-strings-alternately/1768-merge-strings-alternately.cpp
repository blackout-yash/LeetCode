class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int i = 0, j = 0, n = word1.size(), m = word2.size();
        while(i < n && j < m) {
            int temp = ans.size();
            if(temp & 1) ans.push_back(word2[j++]);
            else ans.push_back(word1[i++]);
        }
        while(i < n) ans.push_back(word1[i++]);
        while(j < m) ans.push_back(word2[j++]);
        return ans;
    }
};
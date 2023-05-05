class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    int maxVowels(string s, int k) {
        int j = 0, curr = 0, ans = 0;
        for(int i = 0; i < s.size(); i++) {
            curr += isVowel(s[i]);
            while(i - j == k - 1) {
                ans = max(ans, curr);
                curr -= isVowel(s[j]);
                j++;
            }
        }
        return ans;
    } 
};
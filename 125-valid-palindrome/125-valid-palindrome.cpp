class Solution {
public: 
    bool notAlpha(char ch){
        if(ch >= 'a' && ch <= 'z') return false;
        else if(ch >= '0' && ch <= '9') return false;
        return true;
    }
    
    bool isPalindrome(int i, int j, string &s) {
        if(i >= j) return true;
        
        char ch1 = tolower(s[i]), ch2 = tolower(s[j]);        
        if(ch1 == ch2) return isPalindrome(i + 1, j - 1, s);
        else if(notAlpha(ch1)) return isPalindrome(i + 1, j, s);
        else if(notAlpha(ch2)) return isPalindrome(i, j - 1, s);
        return false;
    }
    
    bool isPalindrome(string s) {
        int n = s.size();
        return isPalindrome(0, n - 1, s);
    }
};
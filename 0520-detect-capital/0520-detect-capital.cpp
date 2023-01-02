class Solution {
public:
    bool isCapital(char ch) {
        return 'A' <= ch && ch <= 'Z';
    }
    
    bool detectCapitalUse(string word) {
        int capital = 0;
        for(auto x: word) {
            if(isCapital(x)) capital++;
        }
        
        if(capital == 0) return true;
        else if(capital == word.size()) return true;
        else if(capital == 1 && isCapital(word[0])) return true;
        return false;
    }
};
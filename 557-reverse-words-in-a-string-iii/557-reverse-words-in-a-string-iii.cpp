class Solution {
public:
    void reverse(int i, int j, string &s){
        while(i <= j){
            swap(s[i], s[j]);
            i++; j--;
        }
    }
    
    string reverseWords(string s) {
        int i = -1, j;
        for(int k = 0; k < s.size(); k++){
            if(s[k] != ' ') {
                j = k;
                if(i == -1) i = k;
            }
            
            if(s[k] == ' ' || k + 1 == s.size()) {
                reverse(i, j, s);
                i = -1;
            } 
        }
        return s;
    }
};
class Solution {
public:
    string convertToTitle(int columnNumber) {
        long start = 26, size = 1;
        while(start <= columnNumber) {
            columnNumber -= start;
            if(columnNumber) {
                start *= 26; size++;
            }
        }
        
        string ans; 
        while(size-- > 1) {
            int curr = pow(26, size),
                que = columnNumber / curr;
            if(columnNumber % curr == 0) que = ((que - 1) + 26) % 26;
            ans.push_back(char('A' + que));
            columnNumber -= (que * curr);
        }
        int rem = (((columnNumber % 26) - 1) + 26) % 26;
        ans.push_back(char('A' + rem));
        return ans;
    }
};
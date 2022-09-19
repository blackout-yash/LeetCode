class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        else if(!x) return true;
        
        int i = floor(log10(x) + 1) - 1, j = 0;
        while(i >= j){
            int left = ceil(pow(10, i)), right = ceil(pow(10, j));
            int num1 = x / left, num2 = x / right;
            if(num1 % 10 != num2 % 10) return false;
            i--; j++;
        }
        return true;
    }
};
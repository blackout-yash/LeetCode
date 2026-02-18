class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = -1;
        while(n) {
            bool flg = (n & 1);
            if(prev == -1) prev = flg;
            else if(flg == prev) return false;
            prev = flg; n /= 2;
        }
        return true;
    }
};
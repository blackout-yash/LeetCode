class Solution {
public:
    int mirrorDistance(int n) {
        int digits = pow(10, floor(log10(n) + 1)) / 10, temp = n, rev = 0;
        while(temp) {
            rev += (digits * (temp % 10));
            temp /= 10; digits /= 10;
        }
        return abs(n - rev);
    }
};
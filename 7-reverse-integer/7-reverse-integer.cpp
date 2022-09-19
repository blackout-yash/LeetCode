class Solution {
public:
    int reverse(int x) {
        if(!x) return 0;
        
        long ans = 0, num = x, cnt = floor(log10(abs(num)) + 1) - 1;
        while(num){
            ans += ceil(pow(10, cnt)) * (num % 10);
            num /= 10; cnt--;
        } 
        
        if(ans < -pow(2, 31) || ans >= pow(2, 31)) ans = 0;
        
        return ans;
    }
};
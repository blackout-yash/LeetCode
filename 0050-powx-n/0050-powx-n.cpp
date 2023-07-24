class Solution {
public:
    double solve(double x,int n){
        if(n == 0) return 1;
        
        double curr = solve(x, n / 2);
        curr *= curr;
        
        if(n % 2 == 0) return curr;
        return x * curr;
    }
    
    double myPow(double x, int n) {
        double ans=solve(x,abs(n));
        if(n < 0) return 1/ans;
        return ans;
    }
};
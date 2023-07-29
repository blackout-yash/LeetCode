class Solution {
public:
    map <int, map <int, double>> m;
    double soupServings(int a, int b) {
        if(a <= 0 && b <= 0) return 0.5;
        else if(a <= 0) return 1;
        else if(b <= 0) return 0;
        else if(m[a].count(b)) return m[a][b];

        double ans = soupServings(a - 100, b) +
                     soupServings(a - 75, b - 25) +
                     soupServings(a - 50, b - 50) +
                     soupServings(a - 25, b - 75);
        
        return m[a][b] = 0.25 * ans;
    }
    
    double soupServings(int n) {
        if(n > 5000) return 1;
        return soupServings(n, n);
    }
};
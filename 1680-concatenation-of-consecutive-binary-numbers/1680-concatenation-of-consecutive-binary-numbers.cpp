#define ll long long
class Solution {
public:
    int m = 1e9 + 7;
    ll sum(ll a, ll b) {a %= m; b %= m; return (((a + b) % m) + m) % m;}
    ll mul(ll a, ll b) {a %= m; b %= m; return (((a * b) % m) + m) % m;}
    
    int concatenatedBinary(int n) {
        ll ans = 0, power = 1;
        for(int i = n; i >= 1; i--){
            int bits = floor(log2(i) + 1);
            ll curr = mul(i, power);
            ans = sum(ans, curr);
            power = mul(power, 1 << bits);
        }
        return ans;
    }
};
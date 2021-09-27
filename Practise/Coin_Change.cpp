//                 322. Coin Change
// Link - https://leetcode.com/problems/coin-change/



#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fora(a,b) for(ll i=a;i<b;i++)


// Bottom Up
ll coinChange1(vector<ll>& coins, ll amount) {
    if(amount == 0) return 0;
    vector<long long> dp(amount+1, -1);
    for(auto x: coins) {
      if(x <= amount) dp[x] = 1;
    }
    for(ll i = 1; i <= amount; i++){
        long long divide = INT_MAX, sub = INT_MAX;
        long long temp1 = divide, temp2 = sub;
        if(dp[i] == -1){
            for(auto x: coins){
                if(i % x == 0){
                    long long que = i / x;
                    if(que && x != 1) divide = min(divide, que);
                }
                long long diff = i - x;
                if(diff > 0 && dp[diff] != -1) sub = min(sub, dp[diff]+1); 
            }
            if(temp1 != divide || temp2 != sub)dp[i] = min(divide, sub);
        }
    }
return dp[amount];
}


// Bottom Up
ll coinChange2(vector <ll> coins, ll amount){
    vector<ll> dp(amount+1, -1); dp[0] = 0;
    fora(0,amount+1){
        ll minimum = INT_MAX, temp = minimum;
        for(auto x: coins){
            if(x <= i && dp[i-x] != -1){
                minimum = min(minimum, dp[i-x]+1);
            }
        }
        if(minimum != temp) dp[i] = minimum;
    }
return dp[amount];
}



// Top Down
ll coinChange3(vector <ll> coins, ll amount, vector <ll>& dp){
    if(amount == 0) return 0;
    else if(amount < 0) return -1;
    else if(dp[amount]) return dp[amount];

    ll minimum = INT_MAX, temp = minimum;
    for(auto x: coins){
        if(x <= amount){
            ll count = coinChange3(coins, amount-x, dp);
            if(count != -1) minimum = min(minimum, count + 1);
        }
    }
    if(temp != minimum) dp[amount] = minimum;
    else dp[amount] = -1;
return dp[amount];
}


 
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, amount;
        cin >> n >> amount;
        vector <ll> v(n);
        fora(0,n){
            ll x; cin >> x;
            v[i] = x;
        }
        vector <ll> dp(amount+1, 0);
        cout << coinChange1(v, amount) << " " << coinChange2(v, amount) << " " << coinChange3(v, amount, dp) << "\n";
    }
return 0;
}
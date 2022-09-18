#define ll long long
bool compare(pair <ll, ll> &a, pair <ll, ll> &b){
    return a.second < b.second;
}

class Solution {
public:    
    bool isPossible(ll &ans, vector <pair <ll, ll>> &store){
        bool flag = 0;
        for(auto x: store){
            if(-x.first > ans) return false;
            ans += (x.second + x.first);
        } return true;
    }
    
    long long minimumMoney(vector<vector<int>> &transactions) {
        vector <pair <ll, ll>> poss, loss;
        for(auto x: transactions){
            if(x[0] > x[1]) {
                pair <ll, ll> p = {-x[0], x[1]};
                loss.push_back(p);
            } else {
                pair <ll, ll> p = {-x[0], x[1]};
                poss.push_back(p);
            }
        } 
        sort(loss.begin(), loss.end(), compare);
        sort(poss.begin(), poss.end());
                
        ll ans = 1e18, low = 0, high = 1e18;
        while(low <= high) {
            ll mid =  low + (high - low) / 2, temp = mid;
            if(isPossible(temp, loss)) {
                if(isPossible(temp, poss)) {
                    ans = min(ans, mid);
                    high = mid - 1;
                } else low = mid + 1;
            } else low = mid + 1;
        }
        return ans;
    }
};
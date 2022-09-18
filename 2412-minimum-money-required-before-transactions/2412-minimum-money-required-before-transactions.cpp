#define ll long long
bool compare(pair <ll, ll> &a, pair <ll, ll> &b){
    return a.second < b.second;
}

class Solution {
public:    
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
        
        ll ans = 0, curr = 0;
        for(auto x: loss){
            if(-x.first >= curr) {
                ans += (-x.first - curr);
                curr = -x.first;
            } curr += (x.first + x.second); 
        }
        
        for(auto x: poss){
            if(-x.first >= curr) {
                ans += (-x.first - curr);
                curr = -x.first;
            } curr += (x.first + x.second); 
        }
        
        return ans;
    }
};
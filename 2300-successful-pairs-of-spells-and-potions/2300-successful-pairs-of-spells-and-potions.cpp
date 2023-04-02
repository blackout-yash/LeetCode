#define ll long long
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector <ll> req;
        for(auto x: potions) {
            ll a = success, b = x, temp = a / b;
            if(a % b) temp++;
            req.push_back(temp);
        }
        sort(req.begin(), req.end());
        
        vector <int> ans;
        int n = req.size();
        for(auto x: spells) {
            auto it = upper_bound(req.begin(), req.end(), x); 
            ans.push_back(it - req.begin());
        }
        
        return ans;
    }
};
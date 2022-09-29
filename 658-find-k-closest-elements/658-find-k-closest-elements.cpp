class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector <pair <int, int>> temp;
        for(auto y: arr) temp.push_back({abs(x - y), y});
        sort(temp.begin(), temp.end());
        
        vector <int> ans;
        for(auto y: temp){
            if(k) {
                ans.push_back(y.second);
                k--;  
            } else break;
        } sort(ans.begin(), ans.end());
        
        return ans;
    }
};
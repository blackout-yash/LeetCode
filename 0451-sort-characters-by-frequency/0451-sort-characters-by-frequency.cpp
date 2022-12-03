class Solution {
public:
    string frequencySort(string s) {
        map <char, int> m;
        for(auto x: s) m[x]++;
        vector <pair <int, char>> arr;
        for(auto x: m) arr.push_back({-x.second, x.first});
        sort(arr.begin(), arr.end());
        
        string ans;
        for(auto x: arr) {
            char ch = x.second;
            int range = -x.first;
            while(range--) ans.push_back(ch);
        }
        
        return ans;
    }
};
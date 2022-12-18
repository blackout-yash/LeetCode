class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack <int> s;
        vector <int> ans;
        map <int, int> m;
        int n = temperatures.size();
        for(int i = n - 1; i >= 0; i--) {
            int temp = temperatures[i], index = -1;
            while(!s.empty()) {
                if(s.top() > temp) {
                    index = m[s.top()];
                    ans.push_back(index - i);
                    break;
                } else s.pop();
            }
            if(index == -1) ans.push_back(0);
            m[temp] = i;
            s.push(temp);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
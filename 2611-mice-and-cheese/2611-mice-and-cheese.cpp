class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int ans = 0, n = reward1.size();
        for(auto x: reward1) ans += x;
        for(auto x: reward2) ans += x;
        
        priority_queue <int> pq;
        for(int i = 0; i < n; i++) pq.push(reward1[i] - reward2[i]);
        
        while(pq.size()) {
            int curr = pq.top();
            pq.pop();
            if(k) ans += curr, k--;
            else ans -= curr;
        }
        return ans/2;
    }
};

 
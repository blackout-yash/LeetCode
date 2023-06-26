class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;
        
        long long ans = 0, cnt = 0, i = 0, j = costs.size() - 1;
        while(cnt < k){
            while(pq1.size() < candidates && i <= j) pq1.push(costs[i++]);
            while(pq2.size() < candidates && j >= i) pq2.push(costs[j--]);

            int cost1 = pq1.size() ? pq1.top() : 1e9;
            int cost2 = pq2.size() ? pq2.top() : 1e9;

            if(cost1 <= cost2){
               ans += cost1;
               pq1.pop();
            } else {
              ans += cost2;
              pq2.pop();
            }
            cnt++;
        }

        return ans;
    }
};
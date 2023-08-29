class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector <int> preCompute(n + 1);
        for(int i = n - 1; i >= 0; i--) preCompute[i] = (customers[i] == 'Y') + preCompute[i + 1];
        
        int ans = 1e9, curr = 0, ind = -1;
        for(int i = 0; i <= n; i++) {
            if(ans > curr + preCompute[i]) {
                ind = i;
                ans = min(ans, curr + preCompute[i]);
            }
            if(i != n) curr += (customers[i] == 'N');
        }
        return ind;
    } 
};
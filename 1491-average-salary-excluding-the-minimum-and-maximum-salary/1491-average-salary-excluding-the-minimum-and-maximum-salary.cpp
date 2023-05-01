class Solution {
public:
    double average(vector <int> &salary) {
        int n = salary.size(), low = 1e9, high = 0, sum = 0;
        for(auto x: salary) {
            sum += x;
            low = min(x, low);
            high = max(x, high);
        }
        return double(sum - low - high) / (n - 2);
    }
};
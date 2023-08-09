class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        set <int> s;
        int ans = 0, n = rolls.size();
        for(int i = n - 1; i >= 0; i--) {
            s.insert(rolls[i]);
            if(s.size() == k) {
                ans++;
                s.clear();
            }
        }
        return ans + 1;
    }
};
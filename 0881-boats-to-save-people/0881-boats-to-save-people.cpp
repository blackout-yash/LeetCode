class Solution {
public:
    int numRescueBoats(vector<int> &people, int limit) {
        sort(people.begin(), people.end());
        
        int l = 0, r = people.size() - 1, ans = 0;
        while(l <= r) {
            int curr = people[l] + people[r];
            if(curr <= limit) l++;
            ans++; r--;
        }
        
        return ans;
    }
};
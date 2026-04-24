class Solution {
public:
    string updString(char ch, string moves) {
        string ans;
        for(auto x: moves) {
            if(x == '_') ans.push_back(ch);
            else ans.push_back(x); 
        }
        return ans;
    }

    int calDistance(string moves) {
        int ans = 0;
        for(auto x: moves) {
            if(x == 'L') ans++;
            else ans--;
        }
        return abs(ans);
    }

    int furthestDistanceFromOrigin(string moves) {
        return max(calDistance(updString('L', moves)), calDistance(updString('R', moves)));
    }
};
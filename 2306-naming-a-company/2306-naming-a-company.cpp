#define ll long long
class Solution {
public:
    ll distinctNames(vector <string> &ideas) {
        unordered_map <string, bool> m;
        for (auto x : ideas) m[x] = true;

        vector <vector<ll>> store(26, vector<ll> (26));
        for (auto x : ideas) {
            string temp = x;
            for (int i = 0; i < 26; i++) {
                char ch = char('a' + i);
                temp[0] = ch;
                if (!m.count(temp)) store[x[0] - 'a'][ch - 'a']++;
            }
        }

        ll ans = 0;
        for (auto x : ideas) {
            string temp = x;
            for (int i = 0; i < 26; i++) {
                char ch = char('a' + i);
                temp[0] = ch;
                if (!m.count(temp)) ans += store[ch - 'a'][x[0] - 'a'];
            }
        }
        return ans;
    }
};
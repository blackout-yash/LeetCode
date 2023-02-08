//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
#define ll long long
class SingleHash {
public:
    ll base = 31, mod = 1e9 + 7;
    vector <ll> suffix, power;

    SingleHash(string &s) {
        int n = s.size();
        suffix.assign(n + 1, 0);
        power.assign(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = (s[i] + (suffix[i + 1] * base)) % mod;
        }

        power[0] = 1;
        for (int i = 1; i <= n; i++) {
            power[i] = (power[i - 1] * base) % mod;
        }
    }

    int substr(int l, int r) {
        ll ans = suffix[l] - (suffix[r + 1] * power[r - l + 1]);
        return ((ans % mod) + mod) % mod;
    }
};

class Solution {
public:
    vector <int> search(string pat, string txt) {
        SingleHash h1 = SingleHash(pat);
        SingleHash h2 = SingleHash(txt);

        vector <int> ans;
        int m = pat.size(), n = txt.size(),
            hash = h1.substr(0, m - 1);
        for (int i = 0; i < n - m + 1; i++) {
            int curr = h2.substr(i, i + m - 1);
            if (curr == hash) ans.push_back(i + 1);
        }
        if(ans.empty()) return {-1};
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
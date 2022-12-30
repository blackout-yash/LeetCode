//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    bool isAnagram(string a, string b){
        vector <int> freq(26);
        for(auto x: a) freq[x - 'a']++;
        for(auto x: b) freq[x - 'a']--;
        for(auto x: freq) {
            if(x != 0) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends
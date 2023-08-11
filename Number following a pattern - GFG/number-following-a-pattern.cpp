//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
        vector <int> charge, freq;
        int curr = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            curr++;
            if(i + 1 == n || s[i] != s[i + 1]) {
                if(s[i] == 'I') charge.push_back(1);
                else charge.push_back(0);
                freq.push_back(curr);
                curr = 0;
            }
        }
        
        set <char> set;
        for(char i = '1'; i <= '9'; i++) set.insert(i);
        
        freq[0]++;
        string ans;
        int m = freq.size();
        for(int i = 0; i < m; i++) {
            vector <char> temp;
            if(charge[i]) {
                while(freq[i] > 1) {
                    freq[i]--;
                    temp.push_back(*set.begin());
                    set.erase(*set.begin());
                }
                for(auto x: temp) ans.push_back(x);
                if(i + 1 == m) ans.push_back(*set.begin());
                else {
                    int alpha = freq[i + 1];
                    for(auto x: set) {
                        if(alpha) alpha--;
                        else {
                            ans.push_back(x);
                            set.erase(x);
                            break;
                        }
                    }
                }
            } else {
                while(freq[i]--) {
                    temp.push_back(*set.begin());
                    set.erase(*set.begin());
                }
                reverse(begin(temp), end(temp));
                for(auto x: temp) ans.push_back(x);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
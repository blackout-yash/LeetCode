//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    bool areRotations(string s1, string s2){
        int n = s1.size(), m = s2.size();
        if(n != m) return false;
        
        s1 += s1;
        if(s1.find(s2) == string::npos) return false;
        return true;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends
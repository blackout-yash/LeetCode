//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    bool areRotations(string str1, string str2){
        int n = str1.size(), m = str2.size();
        if(n != m) return false;
        
        map <string, int> map;
        for(int i = 0; i < n; i++) {
            string temp;
            temp.push_back(str1[i]);
            temp.push_back(str1[(i + 1) % n]);
            map[temp]++;
        }
        for(int i = 0; i < m; i++) {
            string temp;
            temp.push_back(str2[i]);
            temp.push_back(str2[(i + 1) % m]);
            map[temp]--;
            if(map[temp] == 0) map.erase(temp);
        }
        return map.empty();
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
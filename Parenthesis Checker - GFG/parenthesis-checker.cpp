//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    bool ispar(string str){
        stack <char> s;
        for(auto x: str) {
            if(x == '(' || x == '{' || x == '[') s.push(x);
            else if(s.empty()) return 0;
            else if(x == ')') {
                if(s.top() != '(') return 0;
                s.pop();
            } else if(x == '}') {
                if(s.top() != '{') return 0;
                s.pop();
            } else {
                if(s.top() != '[') return 0;
                s.pop();
            }
        }
        return s.empty();
    }
};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
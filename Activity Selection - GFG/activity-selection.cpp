//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    static bool cmp(vector <int> &a, vector <int> &b) {
        return a[1] < b[1];
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n){
        vector <vector <int>> arr;
        for(int i = 0; i < n; i++) arr.push_back({start[i], end[i]});
        sort(arr.begin(), arr.end(), cmp);
        
        int ans = 1, last = arr[0][1];
        for(int i = 1; i < n; i++) {
            if(arr[i][0] > last) {
                ans++;
                last = arr[i][1];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	int mod=1e9+7;
	public:
		int add(int a, int b, int m = 1e9+7) {a %= m; b %=m; return (((a+b)%m)+m)%m;}

	int func(int idx, int sum, int arr[], vector<vector<int>>&dp){
	   //  if(idx == 0){
    //         if(sum == 0 && arr[0] == 0){
    //             return 2;
    //         }
    //         else if(sum == 0 || arr[0] == sum) return 1;
    //         return 0;
    //     }
    if(idx == -1) {
        if(sum) return 0;
        return 1;
    }
	    
	    if(dp[idx][sum]!=-1) return dp[idx][sum];
	    
	    int not_pick=func(idx-1,sum,arr,dp);
	    int pick=0;
	    if(sum>=arr[idx]) pick=func(idx-1,sum-arr[idx],arr,dp);
	    
	    return dp[idx][sum]= add(not_pick, pick);
	}
	
	int perfectSum(int arr[], int n, int sum){
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return func(n-1,sum,arr,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
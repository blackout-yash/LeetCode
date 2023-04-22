//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	int mod=1e9+7;
	public:

	int func(int idx, int sum, int arr[], vector<vector<int>>&dp){
	     if(idx == 0){
            if(sum == 0 && arr[0] == 0){
                return 2;
            }
            else if(sum == 0 || arr[0] == sum) return 1;
            return 0;
        }
	    
	    if(dp[idx][sum]!=-1) return dp[idx][sum];
	    
	    long not_pick=func(idx-1,sum,arr,dp);
	    long pick=0;
	    if(sum>=arr[idx]) pick=func(idx-1,sum-arr[idx],arr,dp);
	    
	    return dp[idx][sum] = (not_pick + pick) % mod;
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
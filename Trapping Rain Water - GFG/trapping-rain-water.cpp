//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
#define ll long long
class Solution {
public:
    ll trappingWater(int arr[], int n) {
        ll ans = 0, l = 0, r = n - 1, leftMax = -1, rightMax = -1;
        while (l <= r) {
            if (arr[l] <= arr[r]) {
                if (arr[l] >= leftMax) leftMax = arr[l];
                else ans += (leftMax - arr[l]);
                l++;
            } else {
                if (arr[r] >= rightMax) rightMax = arr[r];
                else ans += (rightMax - arr[r]);
                r--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends
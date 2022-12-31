//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	bool isMaxHeapUtil(int a[], int n, int i) {
	    if(i >= n) return true;
		int left = (2 * i) + 1,
		    right = (2 * i) + 2;
		if (left < n && a[i] < a[left]) return false;
		else if (right < n && a[i] < a[right]) return false;
		return isMaxHeapUtil(a, n, left) && isMaxHeapUtil(a, n, right);
	}

	bool isMaxHeap(int a[], int n) {
		return isMaxHeapUtil(a, n, 0);
	}
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	void heaify(int i, int n, vector <int> &arr) {
		int left = (2 * i) + 1,
		    right = (2 * i) + 2;

		if (left < n && right < n && arr[i] <= arr[left] && arr[i] <= arr[right]) {
			if (arr[left] >= arr[right]) {
				swap(arr[i], arr[left]);
				heaify(left, n, arr);
			} else {
				swap(arr[i], arr[right]);
				heaify(right, n, arr);
			}
		} else if (left < n && arr[i] <= arr[left]) {
			swap(arr[i], arr[left]);
			heaify(left, n, arr);
		} else if (right < n && arr[i] <= arr[right]) {
			swap(arr[i], arr[right]);
			heaify(right, n, arr);
		}
	}

	void convertMinToMaxHeap(vector<int> &arr, int n) {
		for (int i = n / 2; i >= 0; i--) {
			heaify(i, n, arr);
		}
	}
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
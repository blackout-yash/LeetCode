//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
	string longestCommonPrefix (string arr[], int n) {
		if (n == 1) return arr[0];

		vector <int> size(arr[0].size());
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < max(arr[0].size(), arr[i].size()); j++) {
				if (arr[0][j] == arr[i][j]) size[j]++;
				else break;
			}
		}

		string ans;
		for (int i = 0; i < arr[0].size(); i++) {
			if (size[i] + 1 == n) ans.push_back(arr[0][i]);
			else break;
		}
		if(ans.empty()) return "-1";
		return ans;
	}
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
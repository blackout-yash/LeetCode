//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

#define pp pair <int, int>
class Solution {
public:
	vector<int> replaceWithRank(vector<int> &arr, int n) {
		priority_queue <pp, vector <pp>, greater <pp>> pq;
		for (int i = 0; i < n; i++) pq.push({arr[i], i});

		int prev = -1, rank = 0;
		vector <int> ans(n);
		for (int i = 1; i <= n; i++) {
			int num = pq.top().first,
			    ind = pq.top().second;
			pq.pop();

			if (num == prev) ans[ind] = rank;
			else {
				rank++;
				ans[ind] = rank;
				prev = num;
			}
		}
		return ans;
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
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
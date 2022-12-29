//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


#define ppi pair<int, pair<int, int>>
class Solution{
public:
	vector<int> mergeKArrays(vector <vector<int>> arr, int k) {
		vector <int> ans;
		priority_queue <ppi, vector <ppi>, greater <ppi>> pq;
		for (int i = 0; i < k; i++) pq.push({arr[i][0], {i, 0}});
		while (!pq.empty()) {
			auto it = pq.top();
			int num = it.first,
			    x = it.second.first,
			    y = it.second.second;
			pq.pop();

			ans.push_back(num);
			if (y + 1 != k) pq.push({arr[x][y + 1], {x, y + 1}});
		}
		return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends
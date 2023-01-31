//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    vector <int> leftMax(int n, vector <int> &asteroids) {
        stack <int> s;
        vector <int> ans(n);
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) s.push(asteroids[i]);
            else {
                int num = -asteroids[i];
                while (s.size()) {
                    if (s.top() < num) s.pop();
                    else break;
                }
                
                if (s.empty()) ans[i] = 1;
                else if(num == s.top()) s.pop();
            }
        }
        return ans;
    }

    vector <int> rightMax(int n, vector <int> &asteroids) {
        stack <int> s;
        vector <int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            if (asteroids[i] < 0) s.push(-asteroids[i]);
            else {
                while (s.size()) {
                    if (s.top() < asteroids[i]) s.pop();
                    else break;
                }
                if (s.empty()) ans[i] = 1;
                else if(s.top() == asteroids[i]) s.pop();
            }
        }
        return ans;
    }

    vector<int> asteroidCollision(int n, vector<int> &asteroids) {
        vector <int> prefix = leftMax(n, asteroids),
                     suffix = rightMax(n, asteroids);

        vector <int> ans;
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                if (suffix[i]) ans.push_back(asteroids[i]);
            } else {
                if (prefix[i]) ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
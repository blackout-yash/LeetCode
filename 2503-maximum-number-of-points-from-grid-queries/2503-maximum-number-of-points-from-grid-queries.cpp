class Solution {
public:
	vector <vector <int>> movement = {{ -1, 0}, {0, -1}, {0, 1}, {1, 0}};

	bool isValid(int i, int j, int n, int m) {
		return i >= 0 && i < n && j >= 0 && j < m;
	}

	vector <int> maxPoints(vector<vector<int>> &grid, vector<int> &queries) {
		int n = grid.size(), m = grid[0].size();
		priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
		vector <vector<int>> vis(n, vector<int> (m));
		pq.push({grid[0][0], {0, 0}}); vis[0][0] = 1;

		map <int, int> map;
		for (auto x : queries) map[x] = 0;

		vector <int> temp;
		for (auto x : map) temp.push_back(x.first);

		int cnt = 0, i = 0;
		while (!pq.empty()) {
			auto it = pq.top();
			int wt = it.first,
			    x = it.second.first,
			    y = it.second.second;
			pq.pop();

			if (temp[i] > wt) cnt++;
			else {
                while (i != temp.size()) {
                    if (temp[i] > wt) break;
			        map[temp[i]] = cnt;
			        i++;
		        }
				cnt++; 
				if (i == temp.size()) break;
			}

			for (auto move : movement) {
				int currX = x + move[0],
				    currY = y + move[1];
				if (isValid(currX, currY, n, m) && !vis[currX][currY]) {
                    vis[currX][currY] = 1;
					pq.push({grid[currX][currY], {currX, currY}});
				}
			}
		}

		while (i != temp.size()) {
			map[temp[i]] = cnt;
			i++;
		}

		vector <int> ans;
		for (auto x : queries) ans.push_back(map[x]);

		return ans;
	}
};
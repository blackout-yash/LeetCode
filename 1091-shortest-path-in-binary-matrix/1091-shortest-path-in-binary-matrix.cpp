class Solution {
public:
	vector <vector <int>> movements = {
		{ -1, -1}, { -1, 0}, { -1, 1},
		{0, -1}, {0, 1},
		{1, -1}, {1, 0}, {1, 1}
	};
	
	bool isValid(int i, int j, int n) {
		return i >= 0 && i < n && j >= 0 && j < n;
	}

	int shortestPathBinaryMatrix(vector <vector <int>> &grid) {
		int n = grid.size();
		vector <vector<int>> dist(n, vector<int> (n, 1e9));
		if(!grid[0][0]) dist[0][0] = 1;

		queue <pair<int, pair<int, int>>> pq;
		if(!grid[0][0]) pq.push({1, {0, 0}});

		while (!pq.empty()) {
			int wt = pq.front().first,
			    x = pq.front().second.first,
			    y = pq.front().second.second;
			pq.pop();

			for (auto it : movements) {
				int currX = x + it[0],
				    currY = y + it[1];
				if (isValid(currX, currY, n) && !grid[currX][currY]) {
					if (1 + wt < dist[currX][currY]) {
						dist[currX][currY] = 1 + wt;
						pq.push({dist[currX][currY], {currX, currY}});
					}
				}
			}
		}

		if (dist[n - 1][n - 1] == 1e9) return -1;
		return dist[n - 1][n - 1];
	}
};
class Solution {
public:
	int row, col;
	void ind(int k, int n) {
		row = k / n;
		col = ((k % n) + n - 1) % n;
		if (k % n == 0) row--;
		row = (n - 1) - row;
		if (n & 1) {
			if (row & 1) col = (n - 1 - col);
		} else if (!(row & 1)) col = (n - 1 - col);
	}

	int snakesAndLadders(vector<vector<int>> &board) {
		int n = board.size();
		queue <int> q;
		vector <int> vis((n * n) + 1);
		q.push(1); vis[1] = 1;
		while (!q.empty()) {
			int curr = q.front();
			q.pop();

			if (curr == n * n) return vis[curr] - 1;

			for (int k = curr + 1; k <= min(curr + 6, n * n); k++) {
				ind(k, n);
				int next = (board[row][col] != -1) ? board[row][col] : k;
                
				if (!vis[next]) {
					q.push(next);
					vis[next] = 1 + vis[curr];
				}
			}
		}
		return -1;
	}
};
#define ff first
#define ss second
#define ll long long
#define pp pair<int, int>
#define ppi pair <pair<int, int>, int>

class Solution {
public:
	void insert(ll &prev, vector <int> &ans, priority_queue <pp, vector <pp>, greater <pp>> &pq) {
		auto it = pq.top();
		pq.pop();
		prev += it.ff;
		ans.push_back(it.ss);
	}

	vector <int> getOrder(vector<vector<int>> &tasks) {
		vector <ppi> temp;
		int n = tasks.size();
		for (int i = 0; i < n; i++) temp.push_back({{tasks[i][0], tasks[i][1]}, i});
		sort(temp.begin(), temp.end());

		vector <int> ans;
		ll i = 0, prev = 1;
		priority_queue <pp, vector <pp>, greater <pp>> pq;
		while (i < n) {
			while (i < n) {
				if (pq.empty() || prev >= temp[i].ff.ff) {
					prev = max(prev, 1ll * temp[i].ff.ff);
					pq.push({temp[i].ff.ss, temp[i].ss});
					i++;
				} else break;
			}
			insert(prev, ans, pq);
		}

		while (!pq.empty()) insert(prev, ans, pq);

		return ans;
	}
};
#define pp pair<int, int>
class Solution {
public:
	int leastInterval(vector <char> &tasks, int n) {
		char ch = '*';
		map <char, int> m;
		priority_queue <int> pq;
		for (auto x : tasks) m[x]++;
		for (auto x : m) pq.push(x.second);

		int time = 0;
		priority_queue <pp, vector <pp>, greater <pp>> next;
		while (!pq.empty()) {
			int num = pq.top();
			pq.pop();

			time++;
			if (num > 1) next.push({time + n, num - 1});
            
			while (!next.empty()) {
				if (pq.empty() || next.top().first <= time) {
					time = max(time, next.top().first);
					pq.push(next.top().second);
					next.pop();
				} else break;
			}
		}
		return time;
	}
};
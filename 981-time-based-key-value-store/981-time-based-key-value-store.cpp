class TimeMap {
public:
	map <string, int> m;
	vector <vector<int>> index;
	vector <vector<string>> str;
	TimeMap() {}

	void set(string key, string value, int timestamp) {
		if (m.count(key)) {
			int ind = m[key];
			str[ind].push_back(value);
			index[ind].push_back(timestamp);
		} else {
			m[key] = m.size();
			vector <string> alpha = {value};
			vector <int> beta = {timestamp};
			str.push_back(alpha);
			index.push_back(beta);
		}
	}

	string get(string key, int timestamp) {
		if (!m.count(key)) return "";
		
        int ind = m[key];
		int it = lower_bound(index[ind].begin(), index[ind].end(), timestamp) - index[ind].begin();
		if(it == index[ind].size()) it--;
        
        if (it >= 0) {
            if(index[ind][it] <= timestamp) return str[ind][it];
            else {
                it--;
                if (it >= 0) return str[ind][it];
                return "";
            }
        } else return "";

		return str[ind][it];
	}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
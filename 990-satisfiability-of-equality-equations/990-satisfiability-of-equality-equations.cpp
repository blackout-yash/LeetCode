class DSU {
public:
	vector <int> parent, _size;
    
    DSU (int n){
        parent.resize(n);
        _size.resize(n);        
    }
    
	void makeSet(int v) {
		parent[v] = v;
		_size[v] = 1;
	}

	int findSet(int v) {
		if (v == parent[v]) return v;
		return parent[v] = findSet(parent[v]);
	}

	void unionSets(int a, int b) {
		a = findSet(a);
		b = findSet(b);
		if (a != b) {
			if (_size[a] < _size[b]) swap(a, b);
			parent[b] = a;
			_size[a] += _size[b];
		}
	}
};

class Solution {
public:
    int toInt(char ch){
        int ans = ch - 'a';
        return ans;
    }
    
	bool equationsPossible(vector<string>& equations) {
		DSU *d = new DSU(26);
		for (int i = 0; i < 26; i++) d -> makeSet(i);
        
        for(auto x: equations){
            if(x[1] == '=') d -> unionSets(toInt(x[0]), toInt(x[3]));
        }
        
        for(auto x: equations){
            if(x[1] == '!'){
                if(d -> findSet(toInt(x[0])) == d -> findSet(toInt(x[3]))) return false;
            }
        }
        
        return true;
	}
};
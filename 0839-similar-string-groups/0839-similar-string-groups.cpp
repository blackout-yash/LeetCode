class Solution {
public:
    bool isSimillar(string& a, string& b){
        int diff = 0;
        for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i])
        diff++;

        if(diff > 2)
        return false;
        }

        return true;
    }
    void dfs(vector<vector<int>>& graph, vector<bool>& used, int node){
        if(used[node])
            return;

        used[node] = 1;
        for(int i = 0 ; i < graph[node].size(); i++){
            if(used[graph[node][i]] == false)
                dfs(graph, used, graph[node][i]);
        }
    }

    int numSimilarGroups(vector<string>& strs) {
        vector<vector<int>> graph(strs.size());

        for(int i = 0; i < strs.size(); i++){
            for(int j = i + 1;j < strs.size(); j++){
                if(isSimillar(strs[i], strs[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        vector<bool> used(strs.size(), 0);

        int ans = 0;
        for(int i = 0; i < strs.size(); i++){
            if(used[i] == false){
            dfs(graph, used, i);
            ans++;
            }
        }

        return ans;
    }
};
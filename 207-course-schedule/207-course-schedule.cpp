class Solution {
public:
    bool isCycle(int root, vector <int> &vis, vector <int> &path, vector <vector <int>> &graph){
        vis[root] = path[root] = 1;
        for(int child: graph[root]){
            if(vis[child]){
                if(path[child]) return true;
                continue;
            }
            if(isCycle(child, vis, path, graph)) return true;
        }
        path[root] = 0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector <vector <int>> graph(numCourses);
        vector <int> vis(numCourses), path(numCourses);
        
        for(auto x: prerequisites) graph[x[0]].push_back(x[1]);
        
        for(int i = 0; i < numCourses; i++){
            if(vis[i]) continue;
            else if(isCycle(i, vis, path, graph)) return false;
        }
        
        return true;
    }
};
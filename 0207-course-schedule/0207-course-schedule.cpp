class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector <int> inorder(numCourses);
        vector <vector <int>> graph(numCourses);
        for(auto x: prerequisites) graph[x[0]].push_back(x[1]);

        
        for(int i = 0; i < numCourses; i++){
            for(int child: graph[i]) inorder[child]++;
        }
        
        queue <int> q;
        for(int i = 0; i < numCourses; i++){
            if(inorder[i]) continue;
            q.push(i);
        }
        
        int cnt = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            cnt++;
            
            for(int child: graph[curr]){
                inorder[child]--;
                if(!inorder[child]) q.push(child);
            }
        }
        
        return cnt == numCourses;
    }
};
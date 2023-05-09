class Solution {
public:

    bool isValidIndex(int i, int j, int n, int m){
        return (i >= 0 and j >= 0 and i < n and j < m);
    }

    vector<pair<int,int>> moves = {{0,1},{1,0},{0,-1},{-1,0}};

    void dfs(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &vis, vector<int> &ans,int n, int m, bool up){
        if(!isValidIndex(i,j,n,m) or vis[i][j]) return;
        vis[i][j]=1;
        ans.push_back(matrix[i][j]);    
        if(up) dfs(i-1,j,matrix,vis,ans,n,m,true);
        for(auto x:moves){
            int newI=i+x.first;
            int newJ=j+x.second;
            if((x.first==-1 and x.second==0))
            dfs(newI,newJ,matrix,vis,ans,n,m,true);
            else dfs(newI,newJ,matrix,vis,ans,n,m,false);  
        }
    } 

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> ans;
        vector<vector<int>> vis(n,vector<int> (m,0));
        dfs(0,0,matrix,vis,ans,n,m,true);
        return ans; 
    }
};
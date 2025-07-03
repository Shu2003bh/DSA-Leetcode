class Solution {
public:
bool dfs(int node ,unordered_map<int,list<int>> &adj,vector<bool> &vis,vector<bool> &dfsvis){
    vis[node]=1;
    dfsvis[node]=1;
    for(auto nbr : adj[node]){
        if(!vis[nbr]){
        if(dfs(nbr,adj,vis,dfsvis)) 
            return true;
        }
        
        else if(dfsvis[nbr]){
            return true;
        }
        
    }
    dfsvis[node]=0;
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
          int n = numCourses;
        unordered_map<int,list<int>> adj;
        for(int i =0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
            
        }
        vector<bool> vis(n);
        vector<bool> dfsvis(n);
     ;
        
        for(int i =0;i<n;i++){
            if(!vis[i]){
                bool cycle = dfs(i,adj,vis,dfsvis);
                if(cycle){
                    return false;
                }
            }
        }
            return true;
        
        
    }
};
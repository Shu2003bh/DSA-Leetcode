class Solution {
public:
    bool dfs(int node,unordered_map<int,bool>& vis,unordered_map<int,bool>& dfsvis,unordered_map<int,list<int>> &adj){
        vis[node]=true;
        dfsvis[node]=true;
        for(auto i : adj[node]){
            if(!vis[i]){
                if(dfs(i,vis,dfsvis,adj)) return true;
                
            }
            else if(dfsvis[i]){
                return true;
            }
        }
        dfsvis[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adj;
        for(int i = 0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adj[v].push_back(u);
        }
        unordered_map<int,bool> vis;
        unordered_map<int,bool> dfsvis;

        for(int i =0;i<numCourses;i++){
            if(!vis[i]){
                bool cycle = dfs(i,vis,dfsvis,adj);
                if(cycle){
                    return false;
                }
            }

        }
return true;
        
    }
};
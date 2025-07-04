
class Solution{
    public:
    bool dfs(vector<vector<int>> &adj,vector<bool>&visited,int i,vector<bool>&path,set<int>&s){
        visited[i]=true;
        path[i]=true;
        int V=adj.size();
        for(int j=0;j<adj[i].size();j++){
            if(!path[adj[i][j]]){
                if(!visited[adj[i][j]]){
                    if(dfs(adj,visited,adj[i][j],path,s)){
                        return true;
                    }
                }
            }
            else{
                return true;
            }
            
        }
        s.insert(i);
        path[i]=false;
        return false;
        
    }
    vector<int>eventualSafeNodes(vector<vector<int>>&graph) {
       int V=graph.size();
       vector<bool>visited(V,false);
       vector<bool>path(V,false);
       set<int>s;
       for(int i=0;i<V;i++){
            if(!visited[i]){
               dfs(graph,visited,i,path,s);

            }
        }
        vector<int>final(s.begin(),s.end());
        return final;
      
    }
};
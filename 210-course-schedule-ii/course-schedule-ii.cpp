class Solution {
public:
    bool dfs(int node,stack<int> &st,vector<bool> &dfsvis,vector<bool> &vis,vector<vector<int>> &adj){   
        dfsvis[node]=true;
        vis[node]=true;
        for(auto i : adj[node]){
            if(!vis[i]){
                if(dfs(i,st,dfsvis,vis,adj)){
                    return true;
                }
            }
            else if(dfsvis[i]){
                return true;
            }
        }
        dfsvis[node]=false;
        st.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i =0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);

        }

        stack<int> st;
        vector<int> ans;
        vector<bool> vis(numCourses,false);
        vector<bool> dfsvis(numCourses,false);
        for(int i =0;i<numCourses;i++){
            if(!vis[i]){
               bool cycle = dfs(i,st,dfsvis,vis,adj);
               if(cycle){
                return ans;
               }
            }
        }
        
        while(!st.empty()){
            auto top = st.top();
            st.pop();
            ans.push_back(top);

        }

      return ans;  
    }
};
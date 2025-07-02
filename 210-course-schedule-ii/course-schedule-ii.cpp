class Solution {
public:
bool topo(int node,unordered_map<int,list<int>> &adj,vector<bool> &vis,stack<int> &st,int n,vector<bool> &dfsvis){
    vis[node]=1;
    dfsvis[node]=1;
    for(auto nbr : adj[node]){
        if(!vis[nbr]){
            if(!topo(nbr, adj,vis,st,n,dfsvis)){
                return false;
            }
        }
        else if(dfsvis[nbr]){
                return false;
            }
        
}
      dfsvis[node]=0;
        st.push(node);
      return true;
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        unordered_map<int,list<int>> adj;
        for(int i =0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
            
        }
        vector<bool> vis(n);
        vector<bool> dfsvis(n);
        stack<int> st;
        for(int i =0;i<n;i++)
        {
            if(!vis[i]){
               if(!topo(i,adj,vis,st,n,dfsvis)){
                return {};
               }
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;

        
    }
};
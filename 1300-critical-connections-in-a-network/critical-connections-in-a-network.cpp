class Solution {
public:
        unordered_map<int,list<int>> adj;
    void dfs(int node,int parent,int &timer,vector<int> &low,vector<int> &disc,vector<bool> &vis,vector<vector<int>> &res, unordered_map<int,list<int>> &adj){
        vis[node] = true;
        disc[node]=low[node]=timer++;

        for(auto nbr : adj[node]){
            if(nbr == parent){
                continue;
            }
            if(!vis[nbr]){
                dfs(nbr,node,timer,low,disc,vis,res,adj);
                low[node]=min(low[node],low[nbr]);

                if(low[nbr]>disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                res.push_back(ans);
            }

            }
            else{
                low[node]=min(low[node],disc[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<int>> adj;
        for(int i =0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n);
        vector<int> disc(n);
        vector<int> low(n);
        int timer = 0;
        int parent = -1;
        vector<vector<int>> res;

        for(int i =0;i<n;i++){
            disc[i]=-1;
            low[i]=-1;
        }

        for(int i =0;i<n;i++){
            if(!vis[i]){
                dfs(i,parent,timer,low,disc,vis,res,adj);
            }
        }
        return res;

        
    }
};
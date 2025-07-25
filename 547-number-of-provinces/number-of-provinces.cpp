class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int node){
        visited[node] = true;

        for(int neighbor = 0; neighbor < isConnected.size(); neighbor++){
            if(isConnected[node][neighbor] == 1 && !visited[neighbor])
                dfs(isConnected, visited, neighbor);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;
        vector<bool> visited(n, false);

        for(int node = 0; node < n; node++){
            if(!visited[node]){
                dfs(isConnected, visited, node);
                provinces++;
            }
        }
        
        return provinces;
    }
};
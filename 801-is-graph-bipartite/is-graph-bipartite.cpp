class Solution {
    bool dfs(int node, vector<vector<int>>& graph, vector<int> &col, int color) {
        col[node] = color;

        for(auto nbr : graph[node]) {
            if(col[nbr] == -1) {
                if(dfs(nbr, graph, col, 1 - color) == false)
                    return false;
            }
            else if(col[nbr] == col[node]) {
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n, -1);

        for(int i = 0; i < n; i++) {
            if(col[i] == -1) {
                bool isValid = dfs(i, graph, col, 0);
                if(isValid == false)  // bina ! ke
                    return false;
            }
        }

        return true;
    }
};

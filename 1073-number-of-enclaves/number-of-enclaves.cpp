class Solution {
public:

    void dfs(int x,int y,vector<vector<int>>& grid,vector<vector<int>> &vis){
        int m = grid[0].size();
        int n = grid.size();
        vis[x][y]=1;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        for(int k = 0;k<4;k++){
            int i = x + dx[k];
            int j = y + dy[k];
            if(i>=0  && i<n && j >=0 && j<m && grid[i][j]==1 && vis[i][j]==0){
                dfs(i,j,grid,vis);
            }
        }


    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            if(grid[i][0]==1){
                dfs(i,0,grid,vis);
            }
            if(grid[i][m-1]==1){
                dfs(i,m-1,grid,vis);
            }
        }
        
        for(int i = 0;i<m;i++){
            if(grid[0][i]==1){
                dfs(0,i,grid,vis);
            }
            if(grid[n-1][i]==1){
                dfs(n-1,i,grid,vis);
            }
        }

        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
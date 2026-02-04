class Solution {
public:
    void dfs(int x,int y,vector<vector<int>> &vis,int n,int m,vector<vector<char>>& grid){
        vis[x][y]=1;
        vector<int>dx = {0,1,0,-1};
        vector<int>dy = {1,0,-1,0};
        for(int i =0;i<4;i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if(x1>=0 && x1<n && y1>=0 && y1<m ){
                if(grid[x1][y1] == '1'&& vis[x1][y1]==0)
                dfs(x1,y1,vis,n,m,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]=='1'  && vis[i][j]==0){
                    cnt++;
                    dfs(i,j,vis,n,m,grid);
                }

            }
        }
        return cnt;
        
    }
};
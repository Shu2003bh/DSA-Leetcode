class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int n = grid.size();
        int  m=  grid[0].size();
       int oldcolor = grid[sr][sc];
       if(oldcolor == color){
        return grid;
       }
       queue<pair<int,int>> q;
       vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,-1},{0,1}};
       q.push({sr,sc});
       grid[sr][sc]=color;
       while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            for(auto [dx,dy]:dirs){
                int i = x + dx;
                int j = y + dy;
                if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==oldcolor){
                    grid[i][j]=color;
                    q.push({i,j});
                }
            }
       }
       return grid;
        
    }
};
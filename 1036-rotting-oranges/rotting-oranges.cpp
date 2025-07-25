class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis=grid;
        int cntfresh = 0;
        queue<pair<int,int>> q;
        for(int i =0;i<m;i++ ){
            for(int j = 0;j<n;j++){
                if(vis[i][j]==2){
                    q.push({i,j});
                }
                else if(vis[i][j]==1){
                    cntfresh++;
                    
                }
            }
        }
        if(cntfresh==0){
            return 0;
        }
        if(q.empty()){
            return -1;
        }

        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,-1},{0,1}};
        int min = -1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x,y] = q.front();
                q.pop();
                for(auto [dx,dy] : dirs){
                    int i  = x+dx;
                    int j = y +dy;
                    if((i>=0 && i < m) &&(j>=0 && j<n) && vis[i][j]==1 ){
                        vis[i][j]=2;
                        cntfresh--;
                        q.push({i,j});
                    }
                }
               
            }
             min++;
           
        }
         if(cntfresh == 0){
                return min;
            }
            return -1;



        
    }
};
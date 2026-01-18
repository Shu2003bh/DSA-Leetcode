class Solution {
public:

    bool issafe(int row,int col,vector<vector<bool>>& vis,int n){
        int x = row;
        int y = col;
        while(y>=0){
            if(vis[x][y]==1){
                return false;
            }
            y--;
        }

        x = row;
        y = col;
         while( y>=0 && x>=0){
             if(vis[x][y]==1){
                return false;
            }
            x--;
            y--;

         }

         x = row;
         y = col;

         while(x<n && y>=0){
              if(vis[x][y]==1){
                return false;
            }
            x++;
            y--;
         }
         return true;


    }

    void solve(int col,int n,int &ans,vector<vector<bool>> &vis){
        if(col == n){
            ans++;
            return;
        }


        for(int row =0;row<n;row++){
            if(issafe(row,col,vis,n)){
                vis[row][col]=1;
                solve(col+1,n,ans,vis);
                vis[row][col]=0;


            }

        }
    }
    int totalNQueens(int n) {
        if(n==0){
            return 0;
        }
        int ans = 0;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        solve(0,n,ans,vis);
        return ans;
    }
};
class Solution {
public:
void addsol(int n,vector<vector<string>>&ans,vector<vector<bool>> vis){
    vector<string> temp1;
    for(int i = 0;i<n;i++){
        string temp;
        for(int j =0;j<n;j++){
            if(vis[i][j]==1){
                temp +='Q';
            }
                else{
                    temp += '.';
                }
            


        }
        temp1.push_back(temp);
    }
    ans.push_back(temp1);
}
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

    void solve(int col,int n,vector<vector<string>>&ans,vector<vector<bool>> &vis){
        if(col == n){
            addsol(n,ans,vis);
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
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
         if(n==0){
            return ans;
        }
        
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        solve(0,n,ans,vis);
        return ans;
        
    }
};
class Solution {
public:
    void addsol(int n,vector<vector<string>> &ans,vector<vector<bool>> &vis){
        vector<string> temp;
        for(int i =0;i<n;i++){
            string s;
            for(int j =0;j<n;j++){
                if(vis[i][j]==1){
                    s+= "Q";
                }
                else{
                    s += ".";
                }

            }
            temp.push_back(s);
        }
        ans.push_back(temp);

    }
    bool issafe(int row ,int col,vector<vector<bool>> &vis,int n){
        int x = row ;
        int y = col;
        while(y>=0){
            if(vis[x][y]==1){
                return false;
            }
            y--;

        }
        x = row;
        y = col;

        while(x>=0 && y>=0){
            if(vis[x][y]==1){
                return false;
            }
            y--;
            x--;
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
    void solve(int col,int n,vector<vector<string>> &ans,vector<vector<bool>> &vis){
        if(col == n){
            addsol(n,ans,vis);
            return ;
        }

        for( int row = 0;row<n;row++){
            if(issafe(row,col,vis,n)){
                vis[row][col]=1;
                solve(col+1,n,ans,vis);
                vis[row][col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        solve(0,n,ans,vis);
        return ans;

        
    }
};
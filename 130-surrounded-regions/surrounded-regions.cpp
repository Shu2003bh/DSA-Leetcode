class Solution {
public:

    void dfs(int x,int y,vector<vector<char>>& board,int n,int m){
        board[x][y]='#';
        vector<int>dx = {0,1,0,-1};
        vector<int>dy = {1,0,-1,0};
        for(int i =0;i<4;i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if(x1>=0 && x1<n && y1>=0 && y1<m ){
                if(board[x1][y1]=='O')
                dfs(x1,y1,board,n,m);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int  n = board.size();
        int m = board[0].size();
        for(int i =0;i<m;i++){
            if(board[0][i]=='O'){
                dfs(0,i,board,n,m);

            }

            if(board[n-1][i]=='O'){
                dfs(n-1,i,board,n,m);

            }

        }  

        for(int i =0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(i,0,board,n,m);

            }

            if(board[i][m-1]=='O'){
                dfs(i,m-1,board,n,m);

            }
        }

            for(int i =0;i<n;i++){
                for(int j =0;j<m;j++){
                    if(board[i][j]=='O'){
                        board[i][j]='X';
                    }

                    if(board[i][j]=='#'){
                        board[i][j]='O';
                    
                    }
                }
            }

         

       
    }
};
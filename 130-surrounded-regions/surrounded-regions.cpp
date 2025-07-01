class Solution {
public:
    void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();
        vis[x][y] = 1;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int k = 0; k < 4; k++) {
            int i = x + dx[k];
            int j = y + dy[k];
            if(i >= 0 && i < n && j >= 0 && j < m && board[i][j] == 'O' && vis[i][j] == 0) {
                dfs(i, j, vis, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0) return;
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // check left & right columns
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O') dfs(i, 0, vis, board);
            if(board[i][m-1] == 'O') dfs(i, m-1, vis, board);
        }

        // check top & bottom rows
        for(int i = 0; i < m; i++) {
            if(board[0][i] == 'O') dfs(0, i, vis, board);
            if(board[n-1][i] == 'O') dfs(n-1, i, vis, board);
        }

        // flip remaining 'O' to 'X'
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O' && vis[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

class Solution {
public:
    bool issafe(int row,int col,vector<vector<char>>& board,char digit){
        for(int j = 0;j<9;j++){
           if( board[row][j]==digit){
            return false;
           }
        }

           for(int i = 0;i<9;i++){
           if( board[i][col]==digit){
            return false;
           }
        }

        int strow = (row/3)*3;
        int stcol = (col/3)*3;

        for(int i = strow;i<=strow+2;i++){
            for(int j = stcol;j<=stcol+2;j++){
                if(board[i][j]==digit){
                    return false;
                }
            }
        }
        return true;

    }
    bool solve(vector<vector<char>>& board,int row,int col){
        if(row == 9){
            return true;
        }
        int strow = row;
        int stcol = col+1;

        if(stcol  == 9){
            stcol =0;
            strow +=1;
        }

        if(board[row][col]!='.'){
            return solve(board,strow,stcol);
        }
        else{
            for(char digit = '1';digit<='9';digit++){
                if(issafe(row,col,board,digit)){
                    board[row][col]=digit;
                    if(solve(board,strow,stcol)){
                        return true;
                    }
                    board[row][col]='.';
                }

            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);

        
    }
};
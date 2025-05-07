class Solution {
public:

    bool issafe(vector<vector<char>>& board,int row,int col,char digit){
        for(int j = 0;j<9;j++){
            if(board[row][j]==digit){
                return false;
            }
        }

           for(int i = 0;i<9;i++){
            if(board[i][col]==digit){
                return false;
            }
        }

        int strow = (row/3)*3;
        int stcol = (col/3)*3;

        for(int i =strow;i<=strow+2;i++){
            for(int j =stcol;j<=stcol+2;j++){
                if(board[i][j]==digit){
                    return false;
                }
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board,int row,int col){
        if(row == 9){
        return true;
        }
        int nrow  = row,ncol=col+1;
        if(ncol == 9){
            nrow = row+ 1;
            ncol = 0;
        }

        if(board[row][col]!='.'){
           return helper(board,nrow,ncol);
        }
        else{
            for(char dig = '1';dig<='9';dig++)
            if(issafe(board,row,col,dig))
                {
                    board[row][col] = dig;
                   if(helper(board,nrow,ncol)){
                    return true;
                   } 
                    board[row][col] = '.';
                }
        }
        return false;


    }
    void solveSudoku(vector<vector<char>>& board) {
       helper(board ,0,0);
    }
};
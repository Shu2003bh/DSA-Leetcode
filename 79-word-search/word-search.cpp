class Solution {
public:
    bool solve(int i,int j,vector<vector<char>>& board, string word,int index,int n,int m){
        if(index == word.size()){
            return true;
        }

        if(i<0 ||  j<0 || i>=n || j>=m){
            return false;
        }

        if(word[index]!=board[i][j]){
            return false;
        }

   
        
                    char temp = board[i][j];
                    board[i][j] = '#';
                    bool found = solve(i+1,j,board,word,index+1,n,m)||
                    solve(i-1,j,board,word,index+1,n,m)||
                    solve(i,j+1,board,word,index+1,n,m)||
                    solve(i,j-1,board,word,index+1,n,m);
                    board[i][j]=temp;
        
        return found;

    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0 || board.size()==0){
            return false;
        }
        int index = 0;
        int n = board.size();
        int m = board[0].size();
       for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j]==word[index]){
                    if(solve(i,j,board,word,index,n,m)){
                        return true;
                    }
                   
                }
                

            }
        }
        return false;;
        
    }
};
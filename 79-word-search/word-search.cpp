class Solution {
public:
    bool solve(int i,int j,vector<vector<char>>& board, string word,int index,int n,int m){
        if(word[index]!=board[i][j]){
            return false;
        }
        if(index == word.size()-1){
            return true;
        }

        char temp = board[i][j];
        board[i][j] = '#';
        vector<int> dx = {1,0,-1,0};
        vector<int> dy = {0,1,0,-1};

        for(int k = 0;k<4;k++){
            int x = i + dx[k];
            int y = j + dy[k];
            if(x>=0 && x<n && y>=0 && y<m && board[x][y]!='#'){
               if(solve(x,y,board,word,index+1,n,m)) {
                board[i][j] = temp;
                return true;
                }
            }
        }

        board[i][j]=temp;
        
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0 || board.size()==0){
            return false;
        }
        unordered_map<char,int> mp;
        for(auto i : board){
            for(auto j :i){
                mp[j]++;
            }
        }

        for(auto i : word){
            if(--mp[i]<0){
                return false;
            }
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
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        if(mat.empty()||mat[0].empty()){
            return mat;
        }
        int n = mat.size();
        int m = mat[0].size();
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
                else{
                    mat[i][j]=m*n;
                }
            }
        }
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            for(auto [dx,dy]:dirs){
            int i = x + dx;
                int j = y + dy;
               if(i >= 0 && i < n && j >= 0 && j < m && mat[i][j] > mat[x][y] + 1){
                    mat[i][j] = mat[x][y] + 1;
                    q.push({i, j});
                }
            }

        }
        return mat;
    }
};
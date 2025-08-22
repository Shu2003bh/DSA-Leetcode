class Solution {
public:
    int solvemem(int i,int j, string &a, string &b,vector<vector<int>> &dp){
        if(i==a.size()){
            return 0;
        }
        if(j==b.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = 0;
        if(a[i]==b[j]){
            ans = 1+solvemem(i+1,j+1,a,b,dp);
        }
        else{
            ans = max(solvemem(i,j+1,a,b,dp),solvemem(i+1,j,a,b,dp));
        }
       return  dp[i][j] = ans;

    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return solvemem(0,0,text1,text2,dp);
        
    }
};
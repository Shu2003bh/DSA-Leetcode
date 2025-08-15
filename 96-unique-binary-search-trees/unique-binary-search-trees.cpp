class Solution {
    int solvemem(int n,vector<int> &dp){
        int ans = 0;
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }

        for(int i =1;i<=n;i++){
            ans += solvemem(i-1,dp)*solvemem(n-i,dp);
        }
       return dp[n] = ans;
    }
public:
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return solvemem(n,dp);
        
    }
};
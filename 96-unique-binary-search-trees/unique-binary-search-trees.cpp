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
    int solvetab(int number){
        vector<int> dp(number+1,0);
        dp[0]=1;
        dp[1]=1;

        for(int n =2;n<=number;n++){
            for(int i =1;i<=n;i++){
            dp[n] += dp[i-1]*dp[n-i];
        }
        }
        return dp[number];


    }
public:
    int numTrees(int n) {
        // vector<int> dp(n+1,-1);
        // return solvemem(n,dp);
        return solvetab(n);
        
    }
};
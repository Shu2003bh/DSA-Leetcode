class Solution {
public:
    int solve2(vector<int> cost,vector<int> &dp){
        int n = cost.size();
        dp[0]=cost[0];
        dp[1]=cost[1];

        for(int i =2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
        int solve3(vector<int> cost){
        int n = cost.size();
        int prev2=cost[0];
        int prev =cost[1];

        for(int i =2;i<n;i++){
            int curr =cost[i]+min(prev,prev2);
            prev2 = prev;
            prev = curr;
        }
        return min(prev,prev2);
    }
    int solve(vector<int> cost,int n,vector<int> &dp){
        if(n==0){
            return cost[0];
        }

        if(n==1){
            return cost[1];
        }

        if(dp[n]!=-1){
            return dp[n];
        }

        dp[n]=cost[n]+min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        ///return min(solve(cost,n-1,dp),solve(cost,n-2,dp));
       // return solve2(cost,dp);
       return solve3(cost);
        
        
    }
};
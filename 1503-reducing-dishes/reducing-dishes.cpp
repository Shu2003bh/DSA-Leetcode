class Solution {
public:
    int solve(vector<int>& satisfaction,int index,int time){
        int n = satisfaction.size();
        if(index == n){
            return 0;
        }
        int include = satisfaction[index]*(time+1)+solve(satisfaction,index+1,time+1);
        int exclude = 0 + solve(satisfaction,index+1,time);
        int ans = max(include,exclude);
        return ans;
    }
      int solvemem(vector<int>& satisfaction,int index,int time,vector<vector<int>> &dp){
        int n = satisfaction.size();
        if(index == n){
            return 0;
        }
        if(dp[index][time]!=-1){
            return dp[index][time];
        }

        int include = satisfaction[index]*(time+1)+solvemem(satisfaction,index+1,time+1,dp);
        int exclude = 0 + solvemem(satisfaction,index+1,time,dp);
        int ans = max(include,exclude);
        dp[index][time] = ans;
        return dp[index][time];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solvemem(satisfaction,0,0,dp);
        // return solve(satisfaction,0,0);
        
    }
};
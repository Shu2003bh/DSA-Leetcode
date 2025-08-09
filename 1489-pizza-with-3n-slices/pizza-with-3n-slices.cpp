class Solution {
public:
    int solve(vector<int>& slices,int index,int endindex,int n){
        if(index>endindex ||  n==0){
            return 0;
        }

        int include = slices[index]+solve(slices,index+2,endindex,n-1);
        int exclude = solve(slices,index+1,endindex,n);

        return max(include,exclude);
    }
      int solveMem(vector<int>& slices,int index,int endindex,int n,vector<vector<int>> &dp){
        if(index>endindex ||  n==0){
            return 0;
        }

        if(dp[index][n]!=-1){
            return dp[index][n];
        }

        int include = slices[index]+solveMem(slices,index+2,endindex,n-1,dp);
        int exclude = solveMem(slices,index+1,endindex,n,dp);

        return dp[index][n]= max(include,exclude);
    }

    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp1(k,vector<int>(k,-1));
        vector<vector<int>> dp2(k,vector<int>(k,-1));

        int case1 = solveMem(slices,0,k-2,k/3,dp1);
        int case2 = solveMem(slices,1,k-1,k/3,dp2);
        // int case1 = solve(slices,0,k-2,k/3);
        // int case2 = solve(slices,1,k-1,k/3);

        return max(case1,case2);
        
    }
};
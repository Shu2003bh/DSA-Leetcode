class Solution {
public:
    
    int solve(vector<int>& days, vector<int>& costs,int n,int index){
        if(index>=n){
            return 0;
        }

        int opt1 = costs[0]+solve(days,costs, n,index+1);
        int i;
        for(i = index ;i<n && days[i]<days[index]+7;i++);

        int opt2 = costs[1]+solve(days,costs, n,i);

         for( i = index ;i<n && days[i]<days[index]+30;i++);
        
        int opt3 = costs[2]+solve(days,costs, n,i);

        int ans = min(opt1,min(opt2,opt3));
        return ans;



    }
    int solvemem(vector<int>& days, vector<int>& costs,int n,int index,vector<int> &dp){
        if(index>=n){
            return 0;
        }

        if(dp[index]!=-1){
            return dp[index];
        }

        int opt1 = costs[0]+solvemem(days,costs, n,index+1,dp);
        int i;
        for( i = index ;i<n && days[i]<days[index]+7;i++);

        int opt2 = costs[1]+solvemem(days,costs, n,i,dp);

         for(i = index ;i<n && days[i]<days[index]+30;i++);
        
        int opt3 = costs[2]+solvemem(days,costs, n,i,dp);

        int ans = min(opt1,min(opt2,opt3));
        dp[index]= ans;

        return dp[index];



    }
    int  solvetab(vector<int>& days, vector<int>& costs,int n){
        vector<int> dp(n+1,INT_MAX);
        dp[n] = 0;

        for(int k = n-1;k>=0;k--){
        int opt1 = costs[0]+dp[k+1];
        int i;
        for( i = k ;i<n && days[i]<days[k]+7;i++);

        int opt2 = costs[1]+dp[i] ;

         for(i = k ;i<n && days[i]<days[k]+30;i++);
        
        int opt3 = costs[2]+dp[i];

        int ans = min(opt1,min(opt2,opt3));
        dp[k]= ans;

        }
        return dp[0];
    }
    int solveopt(vector<int>& days, vector<int>& costs){
        int ans =0;
         queue<pair<int,int>> month;
         queue<pair<int,int>> week;

         for(auto day:days){

            while(!month.empty() && month.front().first+30<=day){
                month.pop();
            }

             while(!week.empty() && week.front().first+7<=day){
                week.pop();
            }

            month.push({day,ans+costs[2]});
            week.push({day,ans+costs[1]});

            ans = min(ans+costs[0],min(month.front().second,week.front().second));

         }
         return ans;

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1,-1);
        // return solve(days,costs,365,0);
        // return solvemem(days,costs,n,0,dp);
        // return solvetab(days,costs,n);
        return solveopt(days,costs);
        
    }
};
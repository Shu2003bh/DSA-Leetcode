class Solution {
public:
    void solve(int index,int n ,int k,vector<int> temp,vector<vector<int>> & ans){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        for(int i = index;i<=n;i++){
            temp.push_back(i);
            solve(i+1,n,k,temp,ans);
            temp.pop_back();

        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        if(n==0 || k == 0){
            return ans;
        }
        vector<int> temp;
        solve(1,n,k,temp,ans);
        return ans;
        
    }
};
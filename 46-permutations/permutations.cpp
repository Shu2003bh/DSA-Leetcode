class Solution {
public:
    void solve( vector<int> nums,vector<bool> &visited,vector<int> temp,int n ,vector<vector<int>>& ans){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }

        for(int i = 0;i<n;i++){
            if(visited[i]) continue;
            temp.push_back(nums[i]);
            visited[i]=1;
            solve(nums,visited,temp,n,ans);
            visited[i]=0;
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()==0){
            return ans;
        }
        vector<int> temp;

        int n = nums.size();
        vector<bool> visited(n,false);

        solve(nums,visited,temp,n,ans);
        return ans;


        
    }
};
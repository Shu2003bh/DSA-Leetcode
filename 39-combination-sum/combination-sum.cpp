class Solution {
public:
    void solve(int index ,vector<int>& candidates, int target,vector<int> &res,vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(res);
            return ;
        }
        if(target < 0){
            return ;
        }
        for(int i = index;i<candidates.size();i++)

       {
        res.push_back(candidates[i]);
         solve(i,candidates,        target-candidates[i],res,ans);
         res.pop_back();
       }
       
        

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

         vector<vector<int>> ans;
         vector<int> res;
         solve(0,candidates,target,res,ans);
         return ans;


        
    }
};
class Solution {
public:
 void solve(int index ,vector<int>& candidates, int target,vector<int> &res,  vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(res);
            return ;
        }
        if(target < 0){
            return ;
        }
        for(int i = index;i<candidates.size();i++)

       {
        if(i>index && candidates[i]==candidates[i-1]){
            continue;
        }
        if(candidates[i]>target){
            break;
        }
        res.push_back(candidates[i]);
         solve(i+1,candidates,target-candidates[i],res,ans);
         res.pop_back();
       }
 }
       
        
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans ;
        vector<int> res;
        solve(0,candidates,target,res,ans);
        return ans;


        
    }
};
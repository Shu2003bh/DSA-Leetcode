class Solution {
public:
    void solve(int index,vector<int>& nums, int target,int sum,vector<int> &temp,vector<vector<int>>&ans){
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        if(sum>target){
            return;
        }
        for(int i = index;i<nums.size();i++){
            temp.push_back(nums[i]);
            sum += nums[i];
            solve(i,nums,target,sum,temp,ans);
            sum -= nums[i];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if(candidates.size()==0){
            return ans;
        }
        
        int sum = 0;
        vector<int> temp;
        solve(0,candidates,target,sum,temp,ans);
        return ans;
    }
};
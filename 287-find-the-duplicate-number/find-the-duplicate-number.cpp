class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans;
        for(int i =1;i<=n;i++){
            if(nums[i-1]==nums[i]){
                ans = nums[i];
                break;
            }
        }
        return ans;
        
    }
};
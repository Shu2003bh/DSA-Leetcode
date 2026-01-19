class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = 0;
        int maxi = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            curr_sum = max(nums[i],curr_sum+nums[i]);
            maxi = max(maxi,curr_sum); 
            
            }
            return maxi;
        
    }
};
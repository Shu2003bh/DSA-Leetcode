class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curr_sum = 0;
        int maxi = INT_MIN;
    
        for(int i =0;i<nums.size();i++){
            curr_sum = max(curr_sum+nums[i],nums[i]);
            maxi = max(maxi,curr_sum);
        }

        curr_sum = 0;
        int mini = INT_MAX;
        int sum = 0;    
        for(int i =0;i<nums.size();i++){
            sum += nums[i];
            curr_sum = min(curr_sum+nums[i],nums[i]);
            mini = min(mini,curr_sum);
        }

        if(maxi<0){
            return maxi;
        }

        else
        return max(maxi ,sum- mini);

        
    }
};
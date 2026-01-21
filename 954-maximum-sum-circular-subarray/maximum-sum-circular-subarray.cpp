class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0;
        int curr_sum = 0;
        int curr_sum1 = 0;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i =0;i<nums.size();i++){
            sum += nums[i];
            curr_sum = max(curr_sum+nums[i],nums[i]);
            curr_sum1 = min(curr_sum1+nums[i],nums[i]);

            maxi = max(maxi,curr_sum);
            mini = min(mini,curr_sum1);
        }

        if(maxi<0){
            return maxi;
        }
        return max(maxi,sum-mini);
        
    }
};
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum  =0;
        int max_sum = 0;
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
            if(nums[i]==0){
                sum =0;

            }
            max_sum = max(max_sum,sum);
        }
        return max_sum;
        
    }
};
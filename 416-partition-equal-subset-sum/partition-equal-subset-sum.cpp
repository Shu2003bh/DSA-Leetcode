class Solution {
public:
    bool solveso(vector<int>& nums,int t){
        int n = nums.size();
        vector<int> curr(t+1,0);
        vector<int> next(t+1,0);
        next[0]=1;

        for(int index = n-1;index>=0;index--){
            for(int target =0;target<=t;target++){
                bool include=0;
                if(target-nums[index]>=0)
                 include = next[target-nums[index]];

                bool exclude = next[target];

                curr[target] = include || exclude ;

            }
            next = curr;
        }
        return next[t];

    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i: nums){
            sum += i;
        }
        if(sum%2!=0){
            return 0;
        }
        int target = sum/2;

        return solveso(nums,target);
        
    }
};
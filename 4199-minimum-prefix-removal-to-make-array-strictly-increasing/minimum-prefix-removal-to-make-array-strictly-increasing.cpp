class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size()-1;
        int j = 0;
        for(int i=nums.size()-1;i>=1;i--){
            if(nums[i]<=nums[i-1]){
                break;
            }
            j++;

        }
        return n-j;
        
    }
};
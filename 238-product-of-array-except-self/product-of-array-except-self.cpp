class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        int left =1 ;
        int right = 1;
        for(int i =0;i<n;i++)
        {
            ans[i] *= left;
            left *= nums[i];

            ans[n-i-1] *= right;
            right *= nums[n-i-1];
        }

        return ans;
        
    }
};
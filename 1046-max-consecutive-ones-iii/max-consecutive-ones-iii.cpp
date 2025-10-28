class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zerocnt = 0;
        int left = 0;
        int max_len= 0;
        for(int right =0;right<nums.size();right++){
            if(nums[right]==0){
                zerocnt++;
            }
            while(zerocnt>k){
                if(nums[left]==0)
                zerocnt--;

                left++;
            }
            max_len = max(max_len,right-left+1);
        }
        return max_len;
        

        
    }
};
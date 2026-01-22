class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==0) return -1;
        int n = nums.size()-1;
        int st = 0;
        int end = nums.size()-1;
        int mid = (st+end)/2;
        while(st<end ){
            if(mid>0 && mid<n){
                if(nums[mid]>nums[mid-1]  && nums[mid]>nums[mid+1]){
                    return mid;
                }
            }

            if(nums[mid]<nums[mid+1]){
                st = mid+1;
            }
            else{
                 end = mid-1;
            }
           

            mid = (st+end)/2;

        }
        return st;
        
    }
};
class Solution {
public:
    int solve(int st,int end,vector<int>& nums, int target){

        int mid = (st+end)/2;
        while(st<=end){
        if(nums[mid]== target){
            return mid;
        }

        if(nums[mid]>target){
            end = mid-1;
        }
        else{
            st = mid+1;
        }
         mid = (st+end)/2;

        }

  return st;
    }
    int searchInsert(vector<int>& nums, int target) {
        // if(target == 0)return 0;
        // if(nums.size()==1 && target!=nums[0]) return 0;
        int st =0;
        int end = nums.size()-1;
        return solve(st,end,nums,target);
        

        
    }
};
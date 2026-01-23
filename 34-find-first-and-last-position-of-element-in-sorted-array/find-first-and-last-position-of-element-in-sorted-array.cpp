class Solution {
public:
    int solvelast(int st,int end,int target,vector<int>& nums){
        int ans = -1;
        while(st<=end){
            int mid = (st+end)/2;
            
            if(nums[mid]==target){
                ans = mid;
                st = mid+1;
            }
             else if(nums[mid]<target){
                st = mid+1;

            }
            else{
                end = mid-1;
            }
            
        }
        return ans;
    }
    int solvefirst(int st,int end,int target,vector<int>& nums){
        int ans = -1;
        while(st<=end){
            int mid = (st+end)/2;
            
            if(nums[mid]==target){
                ans = mid;
                end = mid-1;
            }
             else if(nums[mid]<target){
                st = mid+1;

            }
            else{
                end = mid-1;
            }
            
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
            return {-1,-1};
        }
        int n = nums.size()-1;
        int first = solvefirst(0,n,target,nums);
        if(first == -1){
            return {-1,-1};
        }

        int last = solvelast(0,n,target,nums);
        return {first,last};

       
    }
};
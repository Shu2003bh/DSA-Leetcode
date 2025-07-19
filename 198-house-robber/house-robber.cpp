class Solution {
public:
    int solvetab(vector<int> &nums){
        int n = nums.size();
       
       // vector<int> dp(n+1,0) 
       int prev2 = 0;
       int prev1 = nums[0];
       for(int i =1;i<n;i++){
        int inc = prev2+nums[i];
        int exc = prev1+0;

        int ans = max(inc,exc);
        prev2 = prev1;
        prev1 = ans;

       }
       return prev1;
    }

   
    int rob(vector<int>& nums) {
        int n = nums.size();
        //vector<int> first,second;
        if(n==1){
            return nums[0];
        }
        return solvetab(nums);

        // for(int i =0;i<n;i++){
        //     if(i!=n-1){
        //         first.push_back(i);
        //     }
        //     if(i!=0){
        //         second.push_back(i);
        //     }
        // }
        // return max(solvetab(first),solvetab(second));
        
    }
};
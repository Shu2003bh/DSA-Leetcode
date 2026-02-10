class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        unordered_set<int> even;
        unordered_set<int> odd;
        int maxi = 0;
        for(int i =0;i<nums.size();i++){
            for(int j =i;j<nums.size();j++){
                if(nums[j]%2==1){
                    odd.insert(nums[j]);
                }
                else if(nums[j]%2==0){
                    even.insert(nums[j]);

                }

                if(odd.size()==even.size()){
                    maxi = max(maxi,j-i+1);
                }
            }
            odd.clear();
            even.clear();
        }

        return maxi;

        
    }
};
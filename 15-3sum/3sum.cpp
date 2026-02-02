class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        vector<vector<int>> op;
        int  n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>  st;
        for(int i =0;i<n;i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==target){
                    st.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }

                else if(nums[i]+nums[j]+nums[k]<target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }

        for(auto i : st){
            op.push_back(i);
        }
        return op;
        
    }
};
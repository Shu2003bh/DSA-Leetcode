class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;

        int i = 0;
        while(i<n){
            int temp = target- nums[i];
            if(mp.find(temp)!=mp.end()){
                return {i,mp[temp]};
            }
            mp[nums[i]]=i;
            i++;
        }
        return {};
        
    }
};
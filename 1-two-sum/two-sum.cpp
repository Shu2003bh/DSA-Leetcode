class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     unordered_map<int,int> mp;
     for(int i =0;i<nums.size();i++){
        int com = target - nums[i];
        if(mp.find(com)!=mp.end()){
            return{i,mp[com]};
        }
        mp[nums[i]]=i;
     }
     return{};


            
        }
      
        
    
};
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool flag = 0;
        unordered_map<int,int> mp;
        for(int i =0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]] >=2){
                flag  =1 ;
                break;
            }
        }
       

        if(flag){
            return true;
        }
        else{
            return false;
        }
        
    }
};
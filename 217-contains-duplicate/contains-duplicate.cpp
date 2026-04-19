class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i =0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        bool flag = 0;
        for(auto i : mp){
            if(i.second >= 2){
                flag =1;
                
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
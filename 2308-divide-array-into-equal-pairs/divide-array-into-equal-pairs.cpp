class Solution {
public:
    bool divideArray(vector<int>& nums) {
        if(nums.size()%2==1){
            return false;
        }
        unordered_map<int,int> mp;
        for(int i =0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto i : mp){
            int n = i.second;
            if(n%2!=0){
                return false;
            }
        }
        return true;;
        
    }
};
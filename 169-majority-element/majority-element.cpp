class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i :nums){
            mp[i]++;
        }
        int n = nums.size();
        for(auto i :mp){
            if(i.second>n/2){
                return i.first;
            }

        }
        return 0;
        
    }
};
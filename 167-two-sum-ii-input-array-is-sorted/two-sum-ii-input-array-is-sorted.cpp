class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> mp;
        int i = 0;
        while(i<numbers.size()){
            int comp = target - numbers[i];
            if(mp.find(comp)!=mp.end()){
                if(i!=mp[comp]){
                    return {mp[comp]+1,i+1};
                }
            }

            mp[numbers[i]] = i;
            i++;
        }
        return {};
        
    }
};
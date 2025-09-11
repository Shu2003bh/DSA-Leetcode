class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans;
        unordered_map<int,int> freq;
        for(auto i : nums){
            freq[i]++;
        }

        for( auto i : freq){
            if (i.second == 1){
                ans = i.first;
            }
        }
        return ans;
    }
};
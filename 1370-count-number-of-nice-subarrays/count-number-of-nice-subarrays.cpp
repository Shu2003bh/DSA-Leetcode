class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i =0;i<nums.size();i++){
            if(nums[i]%2==0){
                nums[i]=0;
            }else
            nums[i]=1;
        }
        int prefix_sum = 0;
        int cnt = 0;
        mp[0]=1;
        for(int i =0;i<nums.size();i++){
            prefix_sum+=nums[i];
            if(mp.find(prefix_sum-k)!=mp.end()){
                cnt+=mp[prefix_sum-k];
            }
            mp[prefix_sum]++;
        }
        return cnt;
        
        
    }
};
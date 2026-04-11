class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,deque<int>> pos;
        int ans = INT_MAX;
        for(int i =0;i<nums.size();i++){
            int x = nums[i];
            pos[x].push_back(i);
            if(pos[x].size()>3){
                pos[x].pop_front();
            }
            if(pos[x].size()==3){
                int f = pos[x].front();
                int l = pos[x].back();
                ans = min(ans,2*(l-f));
            }
        }
        return ans == INT_MAX ? -1:ans;
        
    }
};
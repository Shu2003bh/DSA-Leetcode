class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        for(auto i : nums){
            mp[i]++;
        }

        for(auto i : mp){
            pq.push({i.second,i.first});
        }

        vector<int> ans;
        while(k!=0){
            auto val = pq.top();
            pq.pop();
            ans.push_back(val.second);
            k--;
        }

        return ans;
    }
};
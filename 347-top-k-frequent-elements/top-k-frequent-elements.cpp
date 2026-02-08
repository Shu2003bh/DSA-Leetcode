class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto i : nums){
            mp[i]++;

        }

        for(auto i : mp){
            pq.push({i.second,i.first});
            if(pq.size()>k){
                pq.pop();
            }

        }

        while(!pq.empty()){
            auto top = pq.top();
            ans.push_back(top.second);
            pq.pop();
        }

        return ans;

        
    }
};
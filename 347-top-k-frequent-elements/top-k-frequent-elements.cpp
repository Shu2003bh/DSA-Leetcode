class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        unordered_map<int,int> mp;
        for(auto i : nums){
            mp[i]++;
        }

        for(auto it : mp){
            if(k>pq.size()){
                pq.push({it.second,it.first});
            }
            else{
                auto top = pq.top();
                if(top.first<it.second){
                    pq.pop();
                    pq.push({it.second,it.first});
                }
            }
        }
        
        while(!pq.empty()){
            auto top =pq.top();
            ans.push_back(top.second);
            pq.pop();
        }

        return ans;
        
    }
};
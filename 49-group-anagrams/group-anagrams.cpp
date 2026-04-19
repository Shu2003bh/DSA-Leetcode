class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> result;
        unordered_map<string,vector<string>> mp;
        for(int i =0;i<strs.size();i++){
            string st = strs[i];
            sort(st.begin(),st.end());
            mp[st].push_back(strs[i]);
        }
        
        for(auto i : mp){
            vector<string> ans;
            for(auto j : i.second){
                ans.push_back(j);

            }
            result.push_back(ans);
        }
        return result;

    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size()!=t.size()) return 0;

        unordered_map<char,int> mp;
        for(auto i : s){
            mp[i]++;
        }

        for(auto i : t){
            mp[i]--;
            if(mp[i]<0){
                return false;
            }

        }

     for(auto i : mp){
        if(i.second!=0){
            return false;
        }
     }
     return true;
    }
};
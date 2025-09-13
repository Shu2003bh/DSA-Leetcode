class Solution {
public:
    int maxFreqSum(string s) {
        int m1 = 0;
        int m2 = 0;
        unordered_map<char,int> mp;
        for(auto i : s){
            mp[i]++;
        }

        for(auto i : mp){
           char a = i.first;
            if(a == 'a' || a== 'e'  || a == 'i' || a == 'o' || a == 'u'){
                int cnt = i.second;
                m1 = max(m1,cnt);
            }
            else{
                int cnt = i.second;
                m2 = max(m2,cnt);
            }
        }
        return m1+m2;
        
    }
};
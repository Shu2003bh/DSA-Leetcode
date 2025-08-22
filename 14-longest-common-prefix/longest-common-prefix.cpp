class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string a = strs.front(),b = strs.back(),ans ;
        for(int i =0 ;i<min(a.size(),b.size()) && a[i]==b[i];i++){
            ans += a[i];
        }
        return ans;
        
    }
};
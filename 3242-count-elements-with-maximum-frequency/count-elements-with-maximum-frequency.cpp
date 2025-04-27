class Solution {
public:
    int maxFrequencyElements(vector<int>& arr) {
        unordered_map<int,int> mp;
        int maxfreq =0;
       int  maxans = 0;
        for(int i =0;i<arr.size() ;i++){
            mp[arr[i]]++;
            maxfreq = max(maxfreq,mp[arr[i]]);
        }
       for(int i =0;i<arr.size() ;i++){
            if(maxfreq == mp[arr[i]]){
                maxans ++;
               
            }
        }
        return maxans;
        
    }
};
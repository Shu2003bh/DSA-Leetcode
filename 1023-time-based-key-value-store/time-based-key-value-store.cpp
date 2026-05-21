class TimeMap {
public:
        unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()){
            return "";
        }
        string ans ;
            auto &arr = mp[key];
            int st = 0;
            int end = arr.size()-1;
            while(st<=end){
                int mid = st+(end-st)/2;
                if(arr[mid].first == timestamp){
                    return arr[mid].second;
                }
                else if(arr[mid].first<timestamp){
                    st = mid+1;
                    ans = arr[mid].second;
                    

                }
                else{
                    end = mid-1; 
                }
            }
        return ans;
    }
};

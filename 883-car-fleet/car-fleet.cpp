class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
         vector<pair<int,int>> mp;
        stack<double> st;
        int n = speed.size();
        for(int i =0;i<speed.size();i++){
            mp.push_back({position[i],speed[i]});
        }
        sort(mp.begin(),mp.end());
        for(int i = n-1;i>=0;i--){
            int dist = mp[i].first;
            int spd = mp[i].second;
            double time = double(target-dist)/spd;

            if(st.empty() || time > st.top()){
                st.push(time);
            }

        }
        return st.size();
        
        
    }
};
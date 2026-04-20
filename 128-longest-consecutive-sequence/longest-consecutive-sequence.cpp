class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto i :nums){
            st.insert(i);
        }
        int maxi = 0;

        for(int i : st ){
            if(st.find(i-1)==st.end()){
                int num = i+1;
                int cnt = 1;
                while(st.find(num)!=st.end()){
                    cnt++;
                    num += 1;
                }
                maxi = max(maxi,cnt);
            }
        }
        return maxi;
    }
};
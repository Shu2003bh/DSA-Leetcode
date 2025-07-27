class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if( nums.size()==0){
            return 0;
        }
        unordered_set<int> st;
        for(auto i : nums){
            st.insert(i);
        }
   
       int longest = 1;
       for(auto i : st){
        if(st.find(i-1)==st.end()){
            int x = i;
            int cnt = 1;
            while(st.find(x+1)!=st.end()){
                x = x +1;
                cnt++;
            }
        longest = max(longest,cnt);
        }
       }
       return longest;
        
    }
};
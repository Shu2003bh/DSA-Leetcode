class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int cnt=0;
       sort(citations.begin(),citations.end());
       reverse(citations.begin(),citations.end());
       for(int i =0;i<n;i++){
        if(i+1<=citations[i]){
            cnt++;
        }
       }
       return cnt;
        
    }
};
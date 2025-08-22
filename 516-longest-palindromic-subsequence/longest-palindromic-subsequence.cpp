class Solution {
public:

    int solveso(string &a, string &b){
        vector<int> curr(b.size()+1,0);
        vector<int> next(b.size()+1,0);
        
        for(int i = a.size()-1;i>=0;i--){
            for(int j =b.size()-1;j>=0;j--){
                int ans = 0;
        if(a[i]==b[j]){
            ans = 1+next[j+1];
        }
        else{
            ans = max(curr[j+1],next[j]);
        }
         curr[j] = ans;

            }
            next = curr;
        }
        return curr[0];

    }
    int longestPalindromeSubseq(string s) {
         string revstr = s;
         reverse(revstr.begin(),revstr.end());
        return solveso(s,revstr);
        
    }
};
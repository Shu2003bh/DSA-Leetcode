class Solution {
public:
    void solve(int n,vector<string> &ans,int open,int close,string temp){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }

        if(open<n){
            
            solve(n,ans,open+1,close,temp+"(");
        }

        if(close<open){
            solve(n,ans,open,close+1,temp+")");
        }

        }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n == 0){
            return ans;
        }
        int open = 0;
        int close = 0;
        string temp;

        solve(n,ans,open,close,temp);
        return ans;
    }

};
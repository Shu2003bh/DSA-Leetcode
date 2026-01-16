class Solution {
public:
    void solve(int index,string digits,unordered_map<char,string> mp,vector<string>& ans,string &temp){
        if(index == digits.size()){
            ans.push_back(temp);
        }

        string letter = mp[digits[index]];
        for(auto ch : letter){
            temp.push_back(ch);
            solve(index+1,digits,mp,ans,temp);
            temp.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
       vector<string> ans;
        if(digits.size()==0){
            return ans;
        }
        unordered_map<char,string> mp{
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
       string  temp;
       solve(0,digits,mp,ans,temp);
       return ans;
        
    }
};
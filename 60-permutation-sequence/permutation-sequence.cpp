class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> ans;
        int fact = 1;
        for(int i =1;i<n;i++){
            fact = fact*i;
            ans.push_back(i);
        }
        ans.push_back(n);
        string res="";
        k = k-1;
        while(true){
            res = res + to_string(ans[k/fact]);
            ans.erase(ans.begin()+k/fact);
            if(ans.size()==0){
                break;
            }
            k = k%fact;
            // if(ans.size()>0)
            fact = fact/ans.size();
        }
        return res;
        
    }
};
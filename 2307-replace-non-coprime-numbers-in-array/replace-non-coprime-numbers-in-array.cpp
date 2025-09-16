class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        for(auto i :nums){
            res.push_back(i);
            while(res.size()>1){
                int a = res.back();
                int b =res[res.size()-2] ;
                int g = gcd(a,b);
                if(g>1){
                    res.pop_back();
                    res.pop_back();
                    long long lcm =(long long) a/g*b;
                    res.push_back((int)lcm);
                }
                else{
                    break;
                }
            }
        }
    return res;
        
    }
};
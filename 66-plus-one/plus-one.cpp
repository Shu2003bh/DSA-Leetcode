class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size()-1;
        for(int i = n;i>=0;i--){
            if(digits[i]!=9){
                digits[i]+=1;
                break;
            }
            else{
                digits[i]=0;
            }
        
        }

        if(digits[0]==0){
            digits[0] =1 ;
            digits.push_back(0);
        }
        
        return digits;
        
    }
};
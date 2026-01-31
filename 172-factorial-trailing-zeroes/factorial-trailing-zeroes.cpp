class Solution {
public:
    int trailingZeroes(int n) {
        int i = 1;
        int cnt = 0;
        while(n/pow(5,i)>0){
            cnt += n/pow(5,i);
            // n = n/pow(5,i);
            i++;
        }
        return cnt ;
        
    }
};
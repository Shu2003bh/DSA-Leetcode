class Solution {
public:
    int trailingZeroes(int n) {
        // int i = 1;
        int cnt = 0;
        // while(n/pow(5,i)>0){
        //     cnt += n/pow(5,i);
        //     i++;
        // }

        while(n>0){
            n = n/5;
            cnt += n;
        }
        return cnt ;
        
    }
};
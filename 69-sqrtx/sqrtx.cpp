class Solution {
public:
    int mySqrt(int n) {
        int st = 0;
        int end = n;
        while(st<=end){
            int mid = (st+end)/2;
            long long sq = 1LL * mid * mid;
            if(sq == n){
                return mid;
            }
            else if(sq > n){
                end = mid-1;
            }
            else{
                 st = mid+1;
            }
        }
        return end;
        
    }
};
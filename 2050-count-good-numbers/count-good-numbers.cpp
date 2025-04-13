
#define MOD 1000000007
class Solution {
public:
    long pow(long long b,long long e){
        if(e==0)
        {
            return 1;
        }
       long half = pow(b,e/2);
       if(e%2==0) return (half*half) % MOD;
       else return (half *half * b)%MOD;
    }

    int countGoodNumbers(long long n) {
        long long a=0;
        long long b=0;

       a = (n+1)/2;
       b = n/2;

      return (int) ((pow(5,a)*pow(4,b))%MOD)
;    



        
        
    }
};
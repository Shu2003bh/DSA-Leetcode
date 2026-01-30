class Solution {
public:

    void power(double x, int n,double ans){
        if(n == 0){
            return;
        }
        ans *=x;
        power(x,n-1,ans);
     

    }

    double myPow(double x, int n) {
        if(x == 0){
            return 0.0;
        }
        if(n == 0){
            return 1.0;
        }
        double ans = x;
        return pow(x,n);
        
    }
};
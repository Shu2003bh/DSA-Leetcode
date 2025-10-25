class Solution {
public:
    int totalMoney(int n) {
        int cnt = 0;
        int sum  = 0;
        while(n>0){
            if(n>=7){
                for(int i =1;i<=7;i++){
                    sum = sum + cnt + i; 
                }
            }
            else{
                for(int i =1;i<=n;i++){
                    sum = sum + cnt + i;
                }
            }

            cnt++;
            n = n-7;
        }
        return sum ;
    }
};
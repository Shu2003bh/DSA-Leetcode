class Solution {
public:
    int totalMoney(int n) {
        int week = 0;
        int money  = 0;
        while(n>0){
            if(n>=7){
                for(int i =1;i<=7;i++){
                    money = money + week + i; 
                }
            }
            else{
                for(int i =1;i<=n;i++){
                    money = money + week + i;
                }
            }

            week++;
            n = n-7;
        }
        return money ;
    }
};
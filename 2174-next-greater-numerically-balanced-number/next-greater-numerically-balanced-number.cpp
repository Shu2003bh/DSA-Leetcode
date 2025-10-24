class Solution {
public:
    bool isbeautiful(int mp[]){
        for(int i =0;i<10;i++){
            if(mp[i]>0  )
            {
                if(mp[i]!=i)
                return false;
            }
        }
        return true;

    }
    int nextBeautifulNumber(int n) {
        int x = n+1 ;
        int num ;
        while(x<10000000){
            int temp = x;
            int mp[10]={0};
            while(temp>0){
                int digit = temp%10;
                mp[digit]++;
                temp = temp/10;
            }
            if(isbeautiful(mp)){
               return x;
            }
            x+=1;
        }

        return -1;
        
    }
};
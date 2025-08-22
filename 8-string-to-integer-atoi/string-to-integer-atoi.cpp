class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        int i = 0;
        int sign = 1;
        int temp;
       while(s[i]==' '){
            i++;
        }
        if(s[i]=='-'){
            sign =-1;
            i++;
        }
        else if(i<s.size() && s[i]=='+'){
            i++;
        }
        while(s[i]=='0'){
            i++;
        }

        while(i<s.size() && isdigit(s[i])){
            temp = s[i]-'0';

            if(ans > INT_MAX/10 || ans==INT_MAX/10  && temp >INT_MAX%10){
                return sign ==1 ? INT_MAX : INT_MIN;
            }
            ans = ans*10+temp;
            i++;
        }
        return sign * ans;


        
    }
};
class Bank {
public:
    unordered_map<int,long long> mp;
    Bank(vector<long long>& balance) {
        for(int i =0;i<balance.size();i++){
            mp[i+1]=balance[i];
        }
        
    }
    bool solved(int account1, int account2){
        if((mp.contains(account1)) && (mp.contains(account2))){
            return true;
        }else
         return false;
    }
    
    bool transfer(int account1, int account2, long long money) {

        bool isexist = solved(account1,account2);
        if(isexist){
            long long m1 = mp[account1];

            if(m1>=money){
                mp[account2]+=money;
                mp[account1]-=money;
                return true;

            }
            
        }
        return false;
        
        
        
    }
    
    bool deposit(int account, long long money) {
            if(mp.contains(account)){
                mp[account]+=money;
                return true;
            }
            
        
        return false;
        
    }
    
    bool withdraw(int account, long long money) {
            if(mp.contains(account)){
                if(money <= mp[account]){
                    mp[account]-=money;
                    return true;
                }
            }
        return false;
       
        
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
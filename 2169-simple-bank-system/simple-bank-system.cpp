class Bank {
public:
    unordered_map<int, long long> mp;
    Bank(vector<long long>& balance) {
        for (int i = 0; i < balance.size(); i++)
            mp[i + 1] = balance[i];
    }

    bool transfer(int account1, int account2, long long money) {
        // Single existence check, direct access       
        if (mp.contains(account1) && mp.contains(account2) && mp[account1] >= money) {
            mp[account1] -= money;
            mp[account2] += money;
            return true;
        }
        return false;
    }

    bool deposit(int account, long long money) {
        if (mp.contains(account)) {
            mp[account] += money;
            return true;
        }
        return false;
    }

    bool withdraw(int account, long long money) {
        if (mp.contains(account) && mp[account] >= money) {
            mp[account] -= money;
            return true;
        }
        return false;
    }
};

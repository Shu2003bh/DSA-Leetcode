class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mini = INT_MAX;
        int maxi = 0;
        int total = 0;
        for(int i =0;i<prices.size();i++){
            mini = min(mini,prices[i]);
            maxi = max(maxi,prices[i]);

            if(maxi >= mini){
                total += (maxi-mini);
                mini = prices[i];
                maxi = 0;
            }
        }
        return total;
    }
};
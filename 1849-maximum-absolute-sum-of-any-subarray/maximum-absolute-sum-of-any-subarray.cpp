class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_sum = INT_MIN;
        int min_sum = INT_MAX;
        int sum = 0;
        for(int i : nums){
            sum +=i;

            max_sum = max((sum),max_sum);

            if (sum<0){
                sum = 0;
            }
        }
        sum = 0;
        for(int i : nums){
            sum +=i;

            min_sum = min((sum),min_sum);

            if (sum>0){
                sum = 0;
            }
        }




        return max(max_sum,abs(min_sum));
        
    }
};
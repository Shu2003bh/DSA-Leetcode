class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int count = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum == k) {
                    count++;
                }
                // if (sum > k) {
                //     sum =0;
                    
                // }
            }
        }
        
        return count;
    }
};
     
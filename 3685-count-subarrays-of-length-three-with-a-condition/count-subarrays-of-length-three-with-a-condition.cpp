class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        // Need at least 3 elements to form a subarray of length 3
        if (n < 3) return 0;
        
        // Check each possible subarray of length 3
        for (int i = 0; i < n - 2; i++) {
            int first = nums[i];      // First number
            int second = nums[i + 1]; // Middle number
            int third = nums[i + 2];  // Last number
            
            // Check if first + third equals exactly half of second
            // Use casting to double to handle decimal division
            if (first + third == (double)second / 2) {
                count++;
            }
        }
        
        return count;
        
    }
};
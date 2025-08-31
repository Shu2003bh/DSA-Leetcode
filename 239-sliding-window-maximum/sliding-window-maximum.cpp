class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // stores indices
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove indices outside current window
            if (!dq.empty() && dq.front() <= i - k) 
                dq.pop_front();
            
            // Remove smaller values from back (they are useless)
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            
            // Add current index
            dq.push_back(i);
            
            // Record the max when we have a full window
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

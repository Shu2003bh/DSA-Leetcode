class KthLargest {
public:
        priority_queue<int,vector<int>,greater<int>> mp;
        int temp;
    KthLargest(int k, vector<int>& nums) {
        temp = k;
        int n = nums.size();
        for(int i =0;i<n;i++){
            mp.push(nums[i]);
            if(mp.size()>k){
                mp.pop();
            }

        }
        
    }
    
    int add(int val) {

        mp.push(val);
       
        if(mp.size()>temp){
           mp.pop();
        }

        return mp.top();



        
    }
};

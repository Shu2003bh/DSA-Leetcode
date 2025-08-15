class Solution {
public:
    int trap(vector<int>& height) {
        int total =0;
        int leftmax = 0;
        int rightmax =0;
        int l = 0;
        int r = height.size()-1;
        while(l<=r){
            if(height[l]>=height[r]){
                if(rightmax>height[r]){
                    total += rightmax-height[r];
                    
                }
                else
                rightmax = height[r];

                r--;

            }
            else{
                    if(leftmax>height[l]){
                        total+=leftmax-height[l];
                        
                    }
                    else{
                        leftmax = height[l];

                    }
                        l++;
                }
            }
        
        return total;
        
    }
};
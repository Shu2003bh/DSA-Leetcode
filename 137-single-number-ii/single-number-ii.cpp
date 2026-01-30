class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0,y =0;
        for (auto i:nums){
            x = (x^i) &~y;
            y = (y^i)&~x;
        }
        return x;
    }
};
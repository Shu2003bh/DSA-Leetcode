class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if(n<3){
            return false;
        }
        int i =0;
        int j = 1;
        int k = 2;
        while(i<n && j<n && k<n){
           if((arr[i]%2==1)&&(arr[j]%2==1) && (arr[k]%2==1)){
            return true;
           }
           i++;
           j++;
           k++;
        }
        return false;
    }
};
class Solution {
public:
bool check(vector<int> base,vector<int> newbox){

    if(base[0]>=newbox[0] && base[1]>=newbox[1] && base[2]>=newbox[2]){
        return true;
    }
    else{
        return false;
    }

}
    int solveso(vector<vector<int>> &arr){
        int n = arr.size();
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
          for(int index =n-1;index>=0;index--){
           for(int prev_index = index-1 ; prev_index>=-1;prev_index--){
                    int include = 0;
                    if(prev_index == -1 || check(arr[index],arr[prev_index]))
                     include =arr[index][2]+next[index+1];
                    
                    
                    int exclude = next[prev_index+1];
        
        curr[prev_index+1] = max(include,exclude);
      
               
           }
           next = curr;
       }
       return next[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &a:cuboids){
            sort(a.begin(),a.end());
        }

        sort(cuboids.begin(),cuboids.end());
        return solveso(cuboids);
        
    }
};
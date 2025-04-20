class Solution {
public:
    void Merge(vector<int>& arr,int low,int mid,int high){
        vector<int> temp;
        int l = low;
        int r = mid+1;
        while(l<=mid && r<=high ){
            if(arr[l]<=arr[r]){
                temp.push_back(arr[l]);
                l++;
            }
            else{
                temp.push_back(arr[r]);
                r++;

            }
        }
            while(l<=mid){
                 temp.push_back(arr[l]);
                l++;

            }
            while(r<=high){
                temp.push_back(arr[r]);
                r++;


            }

            for(int i =low;i<=high;i++){
                arr[i]=temp[i-low];
            }
        

    }
    void Mergesort(vector<int>& arr,int low,int high){
        if(low>=high) return;
        int mid =low+(high-low)/2;
        Mergesort(arr,low,mid);
        Mergesort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }

    void sortColors(vector<int>& nums) {
        int n = nums.size();
        Mergesort(nums,0,n-1);
        
    }
};
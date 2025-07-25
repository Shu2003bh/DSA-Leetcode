class Solution {
public:
int Merge(vector<int> &arr,int low,int mid,int high){
      int cnt = 0;
      vector<int> temp;
      int l = low;
      int  r = mid+1;
      while(l<=mid && r<=high){
          if(arr[l]<=arr[r]){
              temp.push_back(arr[l]);
              l++;
          }
          else{
              temp.push_back(arr[r]);
            //   if(arr[l]>2*arr[r])
            //   cnt += (mid-l+1);
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
          arr[i] = temp[i-low];
      }
      return cnt;
  }
  int countPairs(vector<int> &arr, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (right <= high && (long long)arr[i] > 2LL * arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}
  int Mergesort(vector<int> &arr,int low,int high){
      int cnt = 0;
      if(low>=high){
          return 0;
      }
      int mid = low +(high-low)/2;
      cnt += Mergesort(arr,low,mid);
      cnt += Mergesort(arr,mid+1,high);
      cnt+= countPairs(arr,low,mid,high);
      Merge(arr, low, mid, high);              // Sort the array
    return cnt;
  }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
       return Mergesort(nums,0,n-1);
        
    }
};
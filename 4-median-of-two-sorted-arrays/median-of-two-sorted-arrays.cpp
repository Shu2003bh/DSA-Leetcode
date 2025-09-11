class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n1 = nums1.size();
       int n2 = nums2.size();
       vector<int> arr;
       arr.reserve(n1+n2);
       arr.insert(arr.end(),nums1.begin(),nums1.end());
       arr.insert(arr.end(),nums2.begin(),nums2.end());
       sort(arr.begin(),arr.end());
       int sum =0;

       int n = n1+n2;
        if (n%2!=0){
            return arr[n/2];
        }
        else{
            return (arr[(n/2)-1]+arr[n/2])/2.0 ;
        }
       
    
      
        
    }
};
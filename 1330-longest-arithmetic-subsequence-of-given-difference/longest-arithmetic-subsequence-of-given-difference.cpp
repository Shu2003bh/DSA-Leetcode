// class Solution {
// public:
//     int solve(vector<int>& arr, int diff){
//         int n = arr.size();
//         if(n<2){
//             return n;
//         }
//         unordered_map<int,int> dp[n+1];
//         int ans = 0;
//         for(int i =1;i<n;i++){
//             for(int j =0;j<i;j++){
//                 int cnt =1;
//                 if(dp[j].count(diff)){
//                     cnt = dp[j][diff];
//                 }

//                 dp[i][diff] = 1+cnt;
//                 ans = max(ans,dp[i][diff]);
//             }
//         }
//         return ans;
//     }
//     int longestSubsequence(vector<int>& arr, int difference) {
//         return solve(arr,difference);
        
//     }
// };
class Solution {
public:
    int solve(vector<int>& arr, int difference) {
        int n = arr.size();
        if(n < 2) return n;

        unordered_map<int, int> dp;  // value -> longest length ending at that value
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int prev = arr[i] - difference;
            int cnt = 0;
            if(dp.count(prev)) {
                cnt = dp[prev];
            }
            dp[arr[i]] = 1 + cnt; // extend the subsequence
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }

    int longestSubsequence(vector<int>& arr, int difference) {
        return solve(arr, difference);  // correct variable name
    }
};

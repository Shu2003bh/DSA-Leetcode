/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solved(vector<int>& nums,int low,int high,int n){
        if(low>high || high > n){
            return NULL;
        }
        int mid = low + (high-low)/2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = solved(nums,low,mid-1,n);
        root->right = solved(nums,mid+1,high,n);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        return solved(nums,l,h,n);
        
    }
};
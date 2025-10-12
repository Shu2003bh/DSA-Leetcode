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
    int solved(TreeNode* root,int &ans){
        if(root == NULL){
            return 0;
        }
        const int l = max(0,solved(root->left,ans));
        const int r = max(0,solved(root->right,ans));
        ans = max(ans,root->val+l+r);
        return root->val + max(l,r);

    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solved(root,ans);
        return ans ;
        
        
    }
};
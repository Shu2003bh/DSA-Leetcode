/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) {
         // Your code here
        if(root == NULL){
            return root;
        }
        if(root->val == n1->val || root->val == n2->val){
            return root;
        }
        
        TreeNode* leftans = lowestCommonAncestor(root->left,n1,n2);
        TreeNode* rightans = lowestCommonAncestor(root->right,n1,n2);
        
        if(leftans !=NULL && rightans !=NULL){
            return root;
        }
        else if(leftans ==NULL && rightans !=NULL){
            return rightans;
        }
        
        else if(leftans !=NULL && rightans ==NULL){
            return leftans;
        }
        else{
            return NULL;
        }
        
        
    }
};
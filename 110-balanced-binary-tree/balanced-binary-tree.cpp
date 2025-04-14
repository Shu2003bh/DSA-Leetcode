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
    pair<bool,int> checkbalanced(TreeNode* root){
        if(root == NULL){
            pair<bool,int> p = make_pair(1,0);
            return p;
        }
        pair<bool,int> left = checkbalanced(root->left);
        pair<bool,int> right = checkbalanced(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = abs(left.second-right.second)<=1;

         pair<bool,int> ans;
         ans.second = max(left.second,right.second)+1;
         if(op1 && op2 && op3){
            ans.first = true;
         }
         else{
            ans.first = false;
         }
         return ans;

    }
    bool isBalanced(TreeNode* root) {
        pair<bool,int> ans = checkbalanced(root);
        return ans.first;
        
    }
};
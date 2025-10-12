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
    bool solved(TreeNode* p,TreeNode* q){
        if(p==NULL && q==NULL){
            return true;
        }
        if(p!=NULL && q==NULL){
            return false;
        }
        if(p==NULL && q!=NULL){
            return false;
        }
        bool left = solved(p->left,q->right);
        bool right= solved(q->left,p->right);
        bool c = p->val == q->val;

        if(left && right && c){
            return true;
        }
        else
        return false;
         
    

    }
    bool isSymmetric(TreeNode* root) {
    bool ans = solved(root->left,root->right);
    return ans;

        
    }
};
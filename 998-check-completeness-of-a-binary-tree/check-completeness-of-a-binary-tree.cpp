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
    int cntnode(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int ans = 1+ cntnode(root->left) + cntnode(root->right);
        return ans;
    }
    bool isCBT(TreeNode* root , int index,int count){
        if(root == NULL){
            return true;
        }
        if(index >= count){
            return false;
        }
        else{
            bool left = isCBT(root->left,2*index+1,count);
            bool right = isCBT(root->right,2*index+2,count);
            return left && right;
          }
    }
    bool isCompleteTree(TreeNode* root) {
        int index = 0;
        int totalcnt = cntnode(root);
        if(isCBT(root,index,totalcnt)){
            return true;
        }
        else{
            return false;
        }
        
    }
};
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
    int minDepth(TreeNode* root) {
        // int cnt = 0;
        // if(root == NULL){
        //     return cnt;
        // }
        // queue<TreeNode*> q;
        // q.push(root);
        // while(!q.empty()){
        //     TreeNode* front = q.front();
        //     q.pop();
        //     cnt++;
        //     if(front->left){
        //         q.push(front->left);
        //     }
        //     if(front->right){
        //         q.push(front->right);
        //     }
        // }
        // return cnt;
        if(root == NULL){
            return 0;
        }
        // If one child is NULL, we should use the other child's path
    if (root->left == NULL) {
        return minDepth(root->right) + 1;
    }
    if (root->right == NULL) {
        return minDepth(root->left) + 1;
    }
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        int cnt =min(left,right)+1;

        return cnt;
        
    }
};
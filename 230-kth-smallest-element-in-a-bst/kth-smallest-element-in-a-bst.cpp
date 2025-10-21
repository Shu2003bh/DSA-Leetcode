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
    void solved(TreeNode* root, int k,int &cnt,int &kthsmallest){
        if(!root || cnt>=k){
            return;
        }
        solved(root->left,k,cnt,kthsmallest);

        cnt++;

        if(cnt==k){
            kthsmallest = root->val;
        }

        solved(root->right,k,cnt,kthsmallest);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int kthsmallest;
        solved(root,k,cnt,kthsmallest);
        return kthsmallest;
        
    }
};
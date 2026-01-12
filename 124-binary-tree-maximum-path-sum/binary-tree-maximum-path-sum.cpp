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
    int solve(TreeNode* root,int sum,int &maxisum){
        if(root == NULL){
            return 0;
        }

        int left = max(0,solve(root->left,sum,maxisum));
        int right = max(0,solve(root->right,sum,maxisum));

        sum = root->val+left+right;
        maxisum = max(maxisum,sum);
        return root->val + max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int maxisum = INT_MIN;
        int sum = 0;
        solve(root,sum,maxisum);
        return maxisum;
        
    }
};
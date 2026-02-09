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
    void solve(vector<int> &ans,TreeNode* root){
        if(root == NULL){
            return ;
        }
        solve(ans,root->left);
        ans.push_back(root->val);
        solve(ans,root->right);

    }
    TreeNode* bst(vector<int> &ans,int st,int end){
        if(st>end){
            return NULL;
        }
        int mid = st+(end-st)/2;
        TreeNode* root = new TreeNode(ans[mid]);
        root->left = bst(ans,st,mid-1);
        root->right = bst(ans,mid+1,end);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> tree;
        solve(tree,root);
        // sort(tree.begin(),tree.end());

        TreeNode* node = bst(tree,0,tree.size()-1);
        return node;


        
    }
};
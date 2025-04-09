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
    int find(vector<int>& inorder, int element, int n) {
        for(int i = 0; i < n; i++) {
            if(inorder[i] == element) {
                return i;
            }
        }
        return -1;
    }
    
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int& postIdx, int inStart, int inEnd, int n) {
        if(postIdx < 0 || inStart > inEnd) {
            return NULL;
        }
        
        int element = postorder[postIdx--];
        TreeNode* root = new TreeNode(element);
        
        int position = find(inorder, element, n);
        
        // Right subtree first (postorder property)
        root->right = solve(postorder, inorder, postIdx, position + 1, inEnd, n);
        // Then left subtree
        root->left = solve(postorder, inorder, postIdx, inStart, position - 1, n);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int postIdx = n - 1;
        return solve(postorder, inorder, postIdx, 0, n - 1, n);
    }
};
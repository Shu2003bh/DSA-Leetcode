class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }

    void helper(TreeNode* node, vector<int>& res) {
        if (!node) return;
        res.push_back(node->val);       // Root
        helper(node->left, res);        // Left
        helper(node->right, res);       // Right
    }
};

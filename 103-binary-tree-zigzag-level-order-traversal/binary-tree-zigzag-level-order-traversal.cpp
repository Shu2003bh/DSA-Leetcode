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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL){
            return res;
        }
        bool flag = true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> ans(n);
            for(int i=0;i<n;i++){
                TreeNode* front = q.front();
                q.pop();

                int index = flag ? i:n-i-1;
                ans[index]=front->val;

                if(front->left){
                    q.push(front->left);
                }

                if(front->right){
                    q.push(front->right);
                }

            }
            res.push_back(ans);
            flag = !flag;
        }
        return res;
        
    }
};
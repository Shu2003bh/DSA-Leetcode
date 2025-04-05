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
          vector<vector<int>>  result;
          if(root == NULL){
            return result;
          }
            queue<TreeNode*> q;
            q.push(root);
            bool lefttoright = true;

            while(!q.empty()){
                int n = q.size();
                vector<int>ans(n);

                for(int i =0;i<n;i++){
                        TreeNode* front = q.front();
                        q.pop();

                    int idx = lefttoright ? i:n-i-1;
                    ans[idx] = front->val;

                    if(front->left){
                        q.push(front->left);
                    }
                    if(front->right){
                        q.push(front->right);
                    }
                }
                lefttoright = !lefttoright;
                result.push_back(ans);
                

            }
            return result;
        
    }
};
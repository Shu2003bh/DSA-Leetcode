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
         vector<vector<int>> arr;
         if(root == NULL){
            return arr;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool flag = true;
        while(!q.empty()){
           vector<int> ans;
            int n = q.size();
            for(int i =0;i<n;i++){

                auto top = q.front();
                q.pop();
                ans.push_back(top->val);

                if(top->left){
                    q.push(top->left);
                    
                }

                if(top->right){
                    q.push(top->right);
                    
                    
                }

                
            }
               
                if(!flag){
                    reverse(ans.begin(),ans.end());
                    
                }
                arr.push_back(ans);
                flag = !flag;
        }
        
        return arr;
        
        
    }
};
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        long long res = 0;
        q.push({root,0});
        while(!q.empty()){
            int cnt = q.size();
            long long nmin = q.front().second;
            long long first,last;
            for(int i =0;i<cnt;i++){
            auto front = q.front();
            long long curr_id = q.front().second-nmin;
                q.pop();
                if(i == 0){
                    first = curr_id;
                }
                if(i==cnt-1){
                    last = curr_id;
                                    }
                if(front.first->left){
                    q.push({front.first->left,2*curr_id+1});
                }
                if(front.first->right){
                    q.push({front.first->right,2*curr_id+2});
                }
            }
            res = max(res,last-first+1) ;
        }
        return (int)res;
        
    }
};
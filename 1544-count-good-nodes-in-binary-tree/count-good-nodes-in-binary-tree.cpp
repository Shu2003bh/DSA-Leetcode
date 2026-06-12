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
    void cntNode(TreeNode* root,int maxi,int &cnt){
        if(root == NULL){
            return ;
        }

        if(root->val>=maxi){
            maxi = root->val;
            cnt++;
        }

       cntNode(root->left,maxi,cnt);
        cntNode(root->right,maxi,cnt);

    }
    int goodNodes(TreeNode* root) {

        if(root == NULL){
            return -1;
        }
        int cnt = 0;
        cntNode(root->left,root->val,cnt);
        cntNode(root->right,root->val,cnt);

        cnt +=1;
        return cnt;
        
    }
};

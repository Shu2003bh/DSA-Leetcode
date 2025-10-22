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

class Data{
    public:
    int sum ;
    int mini;
    int maxi;
    bool bst ;

    Data(int sum,int mini ,int maxi ,bool bst){
        this->sum  = sum;
        this->mini = mini;
        this->maxi = maxi;
        this->bst = bst;
    }

};
public:
    Data solved(TreeNode* root ,int &maxsum){
        if(root == NULL){
            return {0,INT_MAX,INT_MIN,true};
        }
        Data left = solved(root->left,maxsum);
        Data right = solved(root->right,maxsum);

        if (left.bst && right.bst && left.maxi < root->val && right.mini > root->val){
            int sum = left.sum+root->val+right.sum;
             maxsum = max(sum,maxsum);
           int mini = min(root->val,left.mini);
           int maxi = max(root->val,right.maxi);
            return  {sum,mini,maxi,true};
        }

        return  {0,0,0,false};
    }

    int maxSumBST(TreeNode* root) {
     
        int maxsum = 0;
        solved(root,maxsum);
        return maxsum ;
        
    }
};
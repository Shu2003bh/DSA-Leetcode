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

    int findpos(int idx,vector<int>& inorder,int n){
        for(int i =0;i<n;i++){
            if(inorder[i]==idx){
                return i;
            }
        }
        return -1;
    }
    
    TreeNode* solved(vector<int>& preorder, vector<int>& inorder,int &index,int st,int end,int n){
        if(index>=n || st>end){
            return NULL;
        }

        int element = preorder[index++];
        int pos = findpos(element,inorder,n);
        TreeNode* root = new TreeNode(element);
        root->left = solved(preorder,inorder,index,st,pos-1,n);
        root->right = solved(preorder,inorder,index,pos+1,end,n);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int index = 0;
        TreeNode* ans = solved(preorder,inorder,index,0,n-1,n);
        return ans;
    }
};
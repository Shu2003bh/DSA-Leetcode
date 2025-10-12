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
    
    TreeNode* solved(vector<int>& postorder, vector<int>& inorder,int &index,int st,int end,int n){
        if(index<0 || st>end){
            return NULL;
        }

        int element = postorder[index--];
        int pos = findpos(element,inorder,n);
        TreeNode* root = new TreeNode(element);
        root->right = solved(postorder,inorder,index,pos+1,end,n);
        root->left = solved(postorder,inorder,index,st,pos-1,n);
        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         int n = postorder.size();
        int index = n-1;
        TreeNode* ans = solved(postorder,inorder,index,0,n-1,n);
        return ans;
        
    }
};
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
    int find(vector<int> inorder,int element,int n){
        for(int i = 0 ;i<n;i++){
            if(inorder[i]==element){
                return i;
            }
           
        }
            return -1;
    }
    TreeNode* solve(vector<int> preorder, vector<int> inorder,int &index,int stidx,int endidx,int n){
        if(index >= n || stidx > endidx){
            return NULL;
        }
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
       int  position = find(inorder , element,n);
       root->left = solve(preorder,inorder,index,stidx,position -1,n);
       root->right = solve(preorder,inorder,index,position+1,endidx,n);

       return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int index=0;
        TreeNode* ans = solve(preorder,inorder,index,0,n-1,n);
        return ans;

        
        
    }
};
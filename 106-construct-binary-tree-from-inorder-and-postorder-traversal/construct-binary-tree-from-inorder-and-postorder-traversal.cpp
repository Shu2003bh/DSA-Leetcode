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
int findpos(vector<int>& inorder,int index ,int n){
        for(int i =0;i<n;i++){
            if(index == inorder[i]){
                return i;
            }
        }
        return -1;
    }

    TreeNode* solve(vector<int>& postorder, vector<int>& inorder,int& index,int stindex,int endindex,int n ){
        if(index<0 || stindex>endindex){
            return NULL;;
        }
        int element = postorder[index--];
        int pos = findpos(inorder,element,n);
        TreeNode* root = new TreeNode(element);
        root->right = solve(postorder,inorder,index,pos+1,endindex,n);
        root->left = solve(postorder,inorder,index,stindex,pos-1,n);
        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n  = postorder.size();
         int index = n-1;
        TreeNode* ans = solve(postorder,inorder,index,0,n-1,n);
        return ans;

        
        
    }
};
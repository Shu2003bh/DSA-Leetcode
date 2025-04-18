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
int findpos(vector<int> inorder,int target,int  n){
    for(int i =0;i<n;i++){
        if(target == inorder[i]){
            return i;
        }
    }
    return -1;
}
TreeNode* solve(vector<int> preorder, vector<int> inorder,int &idx,int stidx,int endidx,int n){
    if(idx >= n || stidx > endidx){
        return NULL;
    }
    int element = preorder[idx++];
    int pos = findpos(inorder,element,n);
    TreeNode* root = new TreeNode(element);
    root->left = solve(preorder,inorder,idx,stidx,pos-1,n);
    root->right = solve(preorder,inorder,idx,pos+1,endidx,n);
    return root;
}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int index = 0;
        return solve(preorder,inorder,index,0,n-1,n);
        
    }
};
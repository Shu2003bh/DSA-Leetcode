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
class BSTIterator {
public:
vector<int> arr;
int i = 0;

    void solve(TreeNode* root){
        if(root == NULL){
            return;
        }
        if(root->left){
            solve(root->left);

        }
        arr.push_back(root->val);
        if(root->right){
            solve(root->right);
        }
    }
    BSTIterator(TreeNode* root) {
       solve(root);
        
    }
    
    int next() {
        int n = arr.size();
        if(i<n){
            return arr[i++];

        }
        return -1;
        
    }
    
    bool hasNext() {
        int n = arr.size();
        if(i<n){
            return true;
        }
        else
        return false;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
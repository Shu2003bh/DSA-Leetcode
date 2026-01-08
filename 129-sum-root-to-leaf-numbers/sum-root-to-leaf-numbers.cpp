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
    void solve(TreeNode* root,int& sum,string st){
        if(root==NULL){
            st.pop_back();
            return;
        }

        st.push_back(root->val + '0');
        if(!root->left && !root->right){
            string s2 = st;
            // reverse(s2.begin(),s2.end());
            sum += stoi(s2);
        }

        if(root->left){
            solve(root->left,sum,st);
        }

        if(root->right){
            solve(root->right,sum,st);
        }
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        string st="";
        solve(root,sum,st);
        return sum;
        
    }
};
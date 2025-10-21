/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };if
 */
class Solution {
public:
    void solved(TreeNode* root,vector<int> &arr){
        if(!root){
            return;
        }
        solved(root->left,arr);
        arr.push_back(root->val);
        solved(root->right,arr);

    }
    bool findTarget(TreeNode* root, int k) {

        vector<int> arr;
        solved(root,arr);
        // sort(arr.begin(),arr.end());

        unordered_map<int,int> mp;
        for(int i =0;i<arr.size();i++){
            int c = k - arr[i];
            if(mp.find(c)!=mp.end()){
                return true;
            }
            mp[arr[i]] = i;
        }
        return false;

        
    }
};
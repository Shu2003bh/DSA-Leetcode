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
    void solved(TreeNode* root,int lvl,int height,map<int,map<int,multiset<int>>> &mp){
        if(root == NULL){
            return ;
        }
        mp[lvl][height].insert(root->val);
        solved(root->left,lvl-1,height+1,mp);
        solved(root->right,lvl+1,height+1,mp);

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> mp;
        solved(root,0,0,mp);

        for(auto i : mp){
            vector<int> col;
            for(auto j : i.second){
                col.insert(col.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(col);
        }

        return ans;

        
    }
};
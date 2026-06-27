/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void solve(TreeNode* root,string& ans){
        if(root == NULL){
            ans += "#,";
            return;
        }

        ans += to_string(root->val)+",";
        solve(root->left,ans);
        solve(root->right,ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string ans;
        solve(root,ans);
        return ans;
        
    }


    TreeNode* solve2(vector<string> &st,int &index){

        if(st[index]=="#"){
            index++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(st[index]));
        index++;

        root->left = solve2(st,index);
        root->right = solve2(st,index);

        return root;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        vector<string> ans;
        string temp;

        for(auto i : data){
            if(i == ','){
                ans.push_back(temp);
                temp = "";
            }
            else{
                temp += i;
            }
        }

        int i = 0;
        return solve2(ans,i);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
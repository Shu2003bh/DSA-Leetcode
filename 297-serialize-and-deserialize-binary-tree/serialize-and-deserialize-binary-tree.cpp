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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        if (root == NULL ){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto top = q.front();
                q.pop();

                if(top == NULL){
                    ans += "null,";
                    continue;
                }
                ans+= to_string(top->val);
                ans+=",";

                q.push(top->left);
                q.push(top->right);

            }
        }
        return ans;

        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return NULL;

        }

        vector<string> st;
        string temp;

        for (char c : data){
            if(c == ','){
                st.push_back(temp);
                temp="";
            }
            else{
                temp += c;
            }
        }

        if(st[0]=="null") return NULL;
        TreeNode* root = new TreeNode(stoi(st[0]));
        queue<TreeNode*> q;
        q.push(root);

        int  i =1;
        while(!q.empty() && i<st.size()){
            auto top = q.front();
            q.pop();

            if(st[i]!="null"){
                top->left = new TreeNode(stoi(st[i]));
                q.push(top->left);
            }
            i++;


             if(st[i]!="null"){
                top->right = new TreeNode(stoi(st[i]));
                q.push(top->right);
            }
            i++;
            
        }
        return root;


        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
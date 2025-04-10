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
    TreeNode* createmapping(TreeNode* root,map<TreeNode* ,TreeNode* > &parentnode,int target){
        TreeNode* res = NULL;
        queue<TreeNode*> q;
        q.push(root);
        parentnode[root] = NULL;

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front->val == target){
                res = front;
            }
            if(front->left){
                parentnode[front->left] = front;
                q.push(front->left);
            }
             if(front->right){
                parentnode[front->right] = front;
                q.push(front->right);
            }
        }
        return res;

    }
    int burntime(TreeNode* root,map<TreeNode* ,TreeNode* > &parentnode){
        int ans = 0;
        map<TreeNode* ,bool> visited;
        visited[root] =  true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            bool flag = 0; 

            int n = q.size();
            for(int i =0;i<n;i++){
                    TreeNode* front = q.front();
                    q.pop();

                    if(front->left && !visited[front->left]){
                        flag =1;
                        q.push(front->left);
                        visited[front->left] = 1;
                    }

                    if(front->right && !visited[front->right]){
                        flag = 1;
                        q.push(front->right);
                        visited[front->right] = 1;
                    }

                    if(parentnode[front] && !visited[parentnode[front]]){
                        flag =1 ;
                        q.push(parentnode[front]);
                        visited[parentnode[front]]=1;
                    }
                    
            }  
                    if(flag == 1)
                    ans++;


        }
        return ans;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode* ,TreeNode* > parentnode;
        TreeNode* target = createmapping(root,parentnode,start);
        int ans = burntime(target,parentnode);
        return ans;
        
    }
};
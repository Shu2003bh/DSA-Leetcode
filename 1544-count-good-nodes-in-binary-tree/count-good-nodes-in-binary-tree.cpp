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
 */ const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}

class Solution {
public:
    void cntNode(TreeNode* root,int maxi,int &cnt){
        if(root == NULL){
            return ;
        }

        if(root->val>=maxi){
            maxi = root->val;
            cnt++;
        }

       cntNode(root->left,maxi,cnt);
        cntNode(root->right,maxi,cnt);

    }
    int goodNodes(TreeNode* root) {

        if(root == NULL){
            return -1;
        }
        int cnt = 0;
        cntNode(root->left,root->val,cnt);
        cntNode(root->right,root->val,cnt);

        cnt +=1;
        return cnt;
        
    }
};

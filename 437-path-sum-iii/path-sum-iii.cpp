class Solution {
public:
    void Solved(TreeNode* root, long long currSum, int targetSum, int &cnt) {
        if(root == NULL) return;

        currSum += root->val;
        if(currSum == targetSum) cnt++;

        Solved(root->left, currSum, targetSum, cnt);
        Solved(root->right, currSum, targetSum, cnt);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;

        int cnt = 0;
        // DFS from current root
        Solved(root, 0, targetSum, cnt);

        // Now call pathSum on left and right children
        cnt += pathSum(root->left, targetSum);
        cnt += pathSum(root->right, targetSum);

        return cnt;
    }
};

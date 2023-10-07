class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;

        int leftSum = 0;
        if (root->left && !root->left->left && !root->left->right) {
            leftSum += root->left->val;
        }
        leftSum += sumOfLeftLeaves(root->left);
        leftSum += sumOfLeftLeaves(root->right);

        return leftSum;
    }
};

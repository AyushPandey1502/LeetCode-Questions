class Solution {
public:
    int findDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(findDepth(root->left), findDepth(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int lst = findDepth(root->left);
        int rst = findDepth(root->right);

        if (abs(lst - rst) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};